#include <stdio.h>
#include <string.h>

int main ()
{
    int line = 1;
    FILE* fp = fopen("search.c", "r");
    if (!fp) {
        fprintf(stderr, "ERROR: failed to open file\n");
        return 1;
    }

    char buf[128];
    while (fgets(buf, sizeof(buf), fp)) {
        if (strstr(buf, "int"))
            printf("%d: %s", line, buf);
        line++;
    }
}