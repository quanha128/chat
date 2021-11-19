#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const* argv[])
{
    char buf[5];
    if (argc != 2) {
        printf("usage: %s <data>\n", argv[0]);
        return 1;
    }
    while (strlen(argv[1])>sizeof(buf)) {
        realloc(buf, 10);
    }
    strcpy(buf, argv[1]);
    printf("%s\n", buf);
    return 0;
}