#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int fd, wlen, rlen; int len,cnt =0;
    char buf[8192];

    fd = open(argv[1], O_RDONLY);
    if (fd < 0) return 1;

    for (;;) {
        rlen = read(fd, buf, sizeof(buf));
        if (rlen < 0) return 1;
        if (rlen == 0) break;
        len += rlen;
    }
    for (int i=0; i<len; i++) {
        if (buf[i] == '\n') cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}