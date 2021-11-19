#include <stdio.h>
#include <ctype.h>

int main()
{
    char data;
    char* str;
    for (;;) {
        data = fgetc(stdin);
        if (data == EOF) break;
        if (isdigit(data) !=0) {
            fputc('*', stdout);
        }
        else fputc(data, stdout);
    }
    return 0;
}