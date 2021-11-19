#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_fgets(char **bufp, size_t *sizep, FILE *fp) {
    size_t len;
    if(fgets(*bufp, *sizep, fp) == NULL) return NULL;
    len = strlen(*bufp);
    while(strchr(*bufp, '\n') == NULL) {
        *sizep += 100;
        *bufp = realloc(*bufp, *sizep);
        if(fgets(*bufp + len, *sizep - len, fp) == NULL) return *bufp;
        len += strlen(*bufp + len);
    }
    return *bufp;
}

int main()
{
    size_t linelen = 256;
    char *buff = malloc(linelen);
    int cnt=1;
    while (my_fgets(&buff, &linelen, stdin)!=NULL) {
        printf("%d   %s", cnt, buff);
        cnt++;
    }
    return 0;
}