#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc != 3){
        fprintf(stderr, "Invalid number of arguments\n");
        return 1;
    }
    else
        printf("%s + %s = %d\n", argv[1], argv[2], atoi(argv[1]) + atoi(argv[2]));
    return 0;
}