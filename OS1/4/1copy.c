#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        perror("Usage: mytail [line_num]\n");
        return 1;
    }
    int num = atoi(argv[1]);
    char c;
    char input[10000];
    int line=0, j=0;
    for(;;) {
        c = fgetc(stdin);
        if (c == EOF) break;
        if (c == '\n') line++;
        input[j] = c;
        j++;
    }
    input[j+1] = '\0';
    int cnt=0;
    for (int i=0; i<10000; i++) {
        if (input[i] == '\n') cnt++;
        if (cnt >= (line-num)) {
            printf("%s", input+i);
            break;
        }
    }
    return 0;
}