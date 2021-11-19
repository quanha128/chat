#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    FILE* fp = fopen(argv[1], "r");
    int c;
    while ((c=fgetc(fp)) != EOF){
        if (islower(c))
            putchar(toupper(c));
        else
            putchar(tolower(c));
    }
    fclose(fp);
    return 0;
}