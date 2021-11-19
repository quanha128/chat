#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    FILE* text = freopen("text.txt", "w", stdin);
    fclose(text);
    FILE* fp = fopen("text.txt", "r");
    if (fp == NULL) {
        perror("No file!\n");
        return 1;
    }
    if (argc != 2) {
        perror("Usage: mytail [line_num]\n");
        return 1;
    }

    int num = atoi(argv[1]);

    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);

    char buffer;
    int cnt=0;
    int pos = size;

    for (;;) {
        pos -= 1;
        fseek(fp, pos, SEEK_SET);
        buffer = fgetc(fp);
        if (buffer == '\n') cnt++;
        if (cnt == (num+1)) {
            fseek(fp, pos+1, SEEK_SET);
            break;
        }
    }

    char str[128];

    while(fgets(str, 128, fp) != NULL) {
        fputs(str, stdout);
    }
    fclose(fp);
    return 0;
}