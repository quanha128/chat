#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

int main(int argc, char* argv[]) {

    for(int i=1; i<argc; i++) {
        int rlen=0,word=0,line=0,len=0,inword=0;
        char buf[500];

        int fd = open(argv[i], O_RDONLY);
        if (fd<0) return 1;

        while (1) {
            rlen = read(fd, buf, sizeof(buf));
            if (rlen < 0) return 1;
            if (rlen == 0) break;
            len += rlen;

            for (int i=0; i<rlen; i++) {
                if (buf[i] == '\n') line++;
                if (isalnum(buf[i])) {
                    inword = 1;
                }
                if ((buf[i]==' '|buf[i]=='\n') && inword==1) {
                    inword = 0;
                    word++;
                }
            }
        }
        printf("%d %d %d %s\n", line, word, len, argv[i]);
        close(fd);
    }
    return 0;
}