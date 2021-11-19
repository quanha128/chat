/* tail -- output the last part of file(s)
   Copyright (C) 1989-2020 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* Can display any amount of data, unlike the Unix version, which uses
   a fixed size buffer and therefore can only deliver a limited number
   of lines.

   Original version by Paul Rubin <phr@ocf.berkeley.edu>.
   Extensions by David MacKenzie <djm@gnu.ai.mit.edu>.
   tail -f for multiple files by Ian Lance Taylor <ian@airs.com>.
   inotify back-end by Giuseppe Scrivano <gscrivano@gnu.org>.  */

#include <config.h>

#include <stdio.h>
#include <assert.h>
#include <getopt.h>
#include <sys/select.h>
#include <sys/types.h>
#include <signal.h>
#ifdef _AIX
# include <poll.h>
#endif

#include "system.h"
#include "argmatch.h"
#include "cl-strtod.h"
#include "die.h"
#include "error.h"
#include "fcntl--.h"
#include "isapipe.h"
#include "posixver.h"
#include "quote.h"
#include "safe-read.h"
#include "stat-size.h"
#include "stat-time.h"
#include "xbinary-io.h"
#include "xdectoint.h"
#include "xnanosleep.h"
#include "xstrtol.h"
#include "xstrtod.h"

#if HAVE_INOTIFY
# include "hash.h"
# include <sys/inotify.h>
#endif

/* Linux can optimize the handling of local files.  */
#if defined __linux__ || defined __ANDROID__
# include "fs.h"
# include "fs-is-local.h"
# if HAVE_SYS_STATFS_H
#  include <sys/statfs.h>
# elif HAVE_SYS_VFS_H
#  include <sys/vfs.h>
# endif
#endif

/* The official name of this program (e.g., no 'g' prefix).  */
#define PROGRAM_NAME "tail"

#define AUTHORS \
  proper_name ("Paul Rubin"), \
  proper_name ("David MacKenzie"), \
  proper_name ("Ian Lance Taylor"), \
  proper_name ("Jim Meyering")

/* Number of items to tail.  */
#define DEFAULT_N_LINES 10

/* Special values for dump_remainder's N_BYTES parameter.  */
#define COPY_TO_EOF UINTMAX_MAX
#define COPY_A_BUFFER (UINTMAX_MAX - 1)

/* FIXME: make Follow_name the default?  */
#define DEFAULT_FOLLOW_MODE Follow_descriptor

enum Follow_mode
{
  /* Follow the name of each file: if the file is renamed, try to reopen
     that name and track the end of the new file if/when it's recreated.
     This is useful for tracking logs that are occasionally rotated.  */
  Follow_name = 1,

  /* Follow each descriptor obtained upon opening a file.
     That means we'll continue to follow the end of a file even after
     it has been renamed or unlinked.  */
  Follow_descriptor = 2
};

/* The types of files for which tail works.  */
#define IS_TAILABLE_FILE_TYPE(Mode) \
  (S_ISREG (Mode) || S_ISFIFO (Mode) || S_ISSOCK (Mode) || S_ISCHR (Mode))

static char const *const follow_mode_string[] =
{
  "descriptor", "name", NULL
};

static enum Follow_mode const follow_mode_map[] =
{
  Follow_descriptor, Follow_name,
};

struct File_spec
{
  /* The actual file name, or "-" for stdin.  */
  char *name;

  /* Attributes of the file the last time we checked.  */
  off_t size;
  struct timespec mtime;
  dev_t dev;
  ino_t ino;
  mode_t mode;

  /* The specified name initially referred to a directory or some other
     type for which tail isn't meaningful.  Unlike for a permission problem
     (tailable, below) once this is set, the name is not checked ever again.  */
  bool ignore;

  /* See the description of fremote.  */
  bool remote;

  /* A file is tailable if it exists, is readable, and is of type
     IS_TAILABLE_FILE_TYPE.  */
  bool tailable;

  /* File descriptor on which the file is open; -1 if it's not open.  */
  int fd;

  /* The value of errno seen last time we checked this file.  */
  int errnum;

  /* 1 if O_NONBLOCK is clear, 0 if set, -1 if not known.  */
  int blocking;

#if HAVE_INOTIFY
  /* The watch descriptor used by inotify.  */
  int wd;

  /* The parent directory watch descriptor.  It is used only
   * when Follow_name is used.  */
  int parent_wd;

  /* Offset in NAME of the basename part.  */
  size_t basename_start;
#endif

  /* See description of DEFAULT_MAX_N_... below.  */
  uintmax_t n_unchanged_stats;
};

/* Keep trying to open a file even if it is inaccessible when tail starts
   or if it becomes inaccessible later -- useful only with -f.  */
static bool reopen_inaccessible_files;

/* If true, interpret the numeric argument as the number of lines.
   Otherwise, interpret it as the number of bytes.  */
static bool count_lines;

/* Whether we follow the name of each file or the file descriptor
   that is initially associated with each name.  */
static enum Follow_mode follow_mode = Follow_descriptor;

/* If true, read from the ends of all specified files until killed.  */
static bool forever;

/* If true, monitor output so we exit if pipe reader terminates.  */
static bool monitor_output;

/* If true, count from start of file instead of end.  */
static bool from_start;

/* If true, print filename headers.  */
static bool print_headers;

/* Character to split lines by. */
static char line_end;

/* When to print the filename banners.  */
enum header_mode
{
  multiple_files, always, never
};

/* When tailing a file by name, if there have been this many consecutive
   iterations for which the file has not changed, then open/fstat
   the file to determine if that file name is still associated with the
   same device/inode-number pair as before.  This option is meaningful only
   when following by name.  --max-unchanged-stats=N  */
#define DEFAULT_MAX_N_UNCHANGED_STATS_BETWEEN_OPENS 5
static uintmax_t max_n_unchanged_stats_between_opens =
  DEFAULT_MAX_N_UNCHANGED_STATS_BETWEEN_OPENS;

/* The process ID of the process (presumably on the current host)
   that is writing to all followed files.  */
static pid_t pid;

/* True if we have ever read standard input.  */
static bool have_read_stdin;

/* If nonzero, skip the is-regular-file test used to determine whether
   to use the lseek optimization.  Instead, use the more general (and
   more expensive) code unconditionally. Intended solely for testing.  */
static bool presume_input_pipe;

/* If nonzero then don't use inotify even if available.  */
static bool disable_inotify;

/* For long options that have no equivalent short option, use a
   non-character as a pseudo short option, starting with CHAR_MAX + 1.  */
enum
{
  RETRY_OPTION = CHAR_MAX + 1,
  MAX_UNCHANGED_STATS_OPTION,
  PID_OPTION,
  PRESUME_INPUT_PIPE_OPTION,
  LONG_FOLLOW_OPTION,
  DISABLE_INOTIFY_OPTION
};

static struct option const long_options[] =
{
  {"bytes", required_argument, NULL, 'c'},
  {"follow", optional_argument, NULL, LONG_FOLLOW_OPTION},
  {"lines", required_argument, NULL, 'n'},
  {"max-unchanged-stats", required_argument, NULL, MAX_UNCHANGED_STATS_OPTION},
  {"-disable-inotify", no_argument, NULL,
   DISABLE_INOTIFY_OPTION}, /* do not document */
  {"pid", required_argument, NULL, PID_OPTION},
  {"-presume-input-pipe", no_argument, NULL,
   PRESUME_INPUT_PIPE_OPTION}, /* do not document */
  {"quiet", no_argument, NULL, 'q'},
  {"retry", no_argument, NULL, RETRY_OPTION},
  {"silent", no_argument, NULL, 'q'},
  {"sleep-interval", required_argument, NULL, 's'},
  {"verbose", no_argument, NULL, 'v'},
  {"zero-terminated", no_argument, NULL, 'z'},
  {GETOPT_HELP_OPTION_DECL},
  {GETOPT_VERSION_OPTION_DECL},
  {NULL, 0, NULL, 0}
};

void
usage (int status)
{
  if (status != EXIT_SUCCESS)
    emit_try_help ();
  else
    {
      printf (_("\
Usage: %s [OPTION]... [FILE]...\n\
"),
              program_name);
      printf (_("\
Print the last %d lines of each FILE to standard output.\n\
With more than one FILE, precede each with a header giving the file name.\n\
"), DEFAULT_N_LINES);

      emit_stdin_note ();
      emit_mandatory_arg_note ();

     fputs (_("\
  -c, --bytes=[+]NUM       output the last NUM bytes; or use -c +NUM to\n\
                             output starting with byte NUM of each file\n\
"), stdout);
     fputs (_("\
  -f, --follow[={name|descriptor}]\n\
                           output appended data as the file grows;\n\
                             an absent option argument means 'descriptor'\n\
  -F                       same as --follow=name --retry\n\
"), stdout);
     printf (_("\
  -n, --lines=[+]NUM       output the last NUM lines, instead of the last %d;\n\
                             or use -n +NUM to output starting with line NUM\n\
      --max-unchanged-stats=N\n\
                           with --follow=name, reopen a FILE which has not\n\
                             changed size after N (default %d) iterations\n\
                             to see if it has been unlinked or renamed\n\
                             (this is the usual case of rotated log files);\n\
                             with inotify, this option is rarely useful\n\
"),
             DEFAULT_N_LINES,
             DEFAULT_MAX_N_UNCHANGED_STATS_BETWEEN_OPENS
             );
     fputs (_("\
      --pid=PID            with -f, terminate after process ID, PID dies\n\
  -q, --quiet, --silent    never output headers giving file names\n\
      --retry              keep trying to open a file if it is inaccessible\n\
"), stdout);
     fputs (_("\
  -s, --sleep-interval=N   with -f, sleep for approximately N seconds\n\
                             (default 1.0) between iterations;\n\
                             with inotify and --pid=P, check process P at\n\
                             least once every N seconds\n\
  -v, --verbose            always output headers giving file names\n\
"), stdou…