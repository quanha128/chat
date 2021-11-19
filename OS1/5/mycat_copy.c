#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    char buf[8192]; int i, j, fd, rlen, wlen;

    for(i=1; i<argc; i++) {
        fd = open(argv[i], O_RDONLY);
        for(;;) {
            rlen = read(fd, buf, sizeof(buf));
            if (rlen < 0) return 1;
            if (rlen == 0) break;
            
            for(j=0; j<rlen; ) {
                wlen = write(STDOUT_FILENO, buf+j, rlen-j);
                if (wlen < 0) return 1;

                j += wlen;
            }
        }
        close(fd);
    }
    return 0;
}