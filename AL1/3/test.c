#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    FILE* src = fopen(argv[1], "rb");
    FILE* dst = fopen(argv[2], "wb");
    fseek(src, 0, SEEK_END);
    int lsize = ftell(src);
    rewind(src);
    char* buffer = (char*) malloc(sizeof(char)*lsize);
    fread(buffer, lsize, 1, src);
    fwrite(buffer, lsize, 1, dst);
    free(buffer);
    fclose(src);
    fclose(dst);
    return 0;
}