#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char* argv[])
{
    if (argc != 2){
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }
    FILE* fp;
    fp = fopen(argv[1],"r");
    if (!fp)
    {
        perror("ERROR");
        return 1;
    }
    char s[128];
    while (fgets(s, sizeof(s), fp)){
        if(strcmp(s, "\n")!=0) printf("%s", s);
    }
    printf("\n");
    fclose(fp);
    return 0;
}