#include <stdio.h>
#include <stdlib.h>

#define IS_DIGIT(c) (48 <= (c) && (c) <=57 ? 1 : 0)

static inline int is_digit(char c)
{
    return (48 <= (c) && (c) <=57 ? 1 : 0);
}

int main()
{
    const char* testcase = "1";
    for (int i=0; testcase[i] != '\0'; i++){
        char c = testcase[i];
        printf("%c %d\n", c, IS_DIGIT(c++));
        printf("%c\n", c);
    }
    for (int i=0; testcase[i] != '\0'; i++){
        char c = testcase[i];
        printf("%c %d\n", c, is_digit(c++));
        printf("%c\n", c);
    }
    return 0;
}