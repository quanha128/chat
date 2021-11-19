#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int er, num, count, i, fd=-1, line=0;
    struct stat fileinfo;
    char* map = NULL;

    if (argc != 3) {
        fprintf(stderr, "Usage: mytail <num> <file>\n");
        return 1;
    }

    num = atoi(argv[1]);

    fd = open(argv[2], O_RDONLY);
    if (fd < 0) goto error;

    er = fstat(fd, &fileinfo);
    if (er < 0) goto error;

    map = (char*)mmap(NULL, fileinfo.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (map == NULL) goto error;

    for (i = 0, count = 0; i < fileinfo.st_size - 1; i++) {
        if (map[i] == '\n') line++;
    }

    for (i = 0; i < fileinfo.st_size - 1; i++) {
        if (map[i] == '\n') count++;
        if (count > line-num) putc(map[i], stdout);
    }

    munmap(map, fileinfo.st_size);
    close(fd);
    
    return 0;

 error:
    if (map) munmap(map, fileinfo.st_size);
    if (fd >= 0) close(fd);
    fprintf(stderr, "ERROR\n");
    return 1;
}