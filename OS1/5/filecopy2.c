#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        perror("Usage filecopy2 [src] [dst]\n");
        return 1;
    }

    int src, dst, wlen, rlen;
    char buf[1];

    src = open(argv[1], O_RDONLY);
    if (src < 0) goto error;

    dst = open(argv[2], O_WRONLY|O_CREAT, 0755);
    if (dst < 0) goto error;

    for (;;) {
        rlen = read(src, buf, sizeof(buf));
        if (rlen < 0) goto error;
        if (rlen == 0 ) break;
        for (int i=0; i<rlen; ) {
            wlen = write(dst, buf+i, rlen-i);
            if (wlen < 0) goto error;
            i += wlen;
        }
    }

    close(dst);
    close(src);
    return 0;
error:
    perror("Error reading/writing file\n");
    return 1;
}