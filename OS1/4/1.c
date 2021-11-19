#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        perror("Usage: mytail [line_num]\n");
        return 1;
    }
    int num = atoi(argv[1]);
    fseek(stdin, 0, SEEK_END);
    size_t size = ftell(stdin);
    char *buffer = malloc((size+1) * sizeof(char));
    int cnt=0;

    for (int i=0; i<size; i++) {
        fseek(stdin, size-1-i, SEEK_SET);
        buffer[i] = fgetc(stdin);
        if ((buffer[i]) == '\n') cnt++;
        if (cnt == (num+1)) {
            // fseek(stdin, size-i, SEEK_SET);
            break;
        }
    }
    int len = strlen(buffer);
    for (int k=0; k<len; k++) {
        fputc(buffer[k], stdout);
    }
    return 0;
}