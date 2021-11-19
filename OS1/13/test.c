// copy.c
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int file_size(int fd) {
    struct stat sb;
    if (fstat(fd, &sb)) {
        return -1;
    }
    return sb.st_size;
}

int main(int argc, char *argv[]) {

    if (argc < 3) {
        fprintf(stderr, "require file path.\n");
        return -1;
    }
    char *in_path = argv[1];
    char *out_path = argv[2];
    int in_fd = open(in_path, O_RDONLY);
    int out_fd = open(out_path, O_CREAT | O_RDWR, 0666);

    int fsize = file_size(in_fd);
    if (fsize < 0) {
        return -1;
    }
    if (truncate(out_path, fsize) < 0) {
        fprintf(stderr, "failed to expand file size to %d\n", fsize);
    }

    char *in = mmap(NULL, fsize, PROT_READ, MAP_SHARED, in_fd, 0);
    if (in == MAP_FAILED) {
        fprintf(stderr, "failed to mmap\n");
        return -1;
    }
    char *out = mmap(NULL, fsize, PROT_WRITE, MAP_SHARED, out_fd, 0);
    if (out == MAP_FAILED) {
        fprintf(stderr, "failed to mmap\n");
        return -1;
    }

    // Copy data from `in` to `out`.
    for (int i=0; i<fsize; i++) {
        out[i] = in[i];
    }
 
    // Write back data in memory to disk.
    msync(out, fsize, MS_SYNC);
    
    // unmap memories and close file descriptors.
    munmap(in, fsize);
    munmap(out, fsize);

    return 0;
}