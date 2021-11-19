#include <stdio.h>
#include <string.h>

size_t my_strlen(const char* s)
{
    size_t i;
    for (i=0; s[i]!= '\0'; i++)
        ;
    return i;
}

char* my_strcpy(char* dst, const char* src)
{
    size_t i;
    for (i=0; src[i] != 0; i++){
        dst[i] = src[i];
    }
    dst[i] = '\0';
    return dst;
}

char* my_strcat(char* dst, const char* src)
{
    size_t i;
    for (i=0; i<=)
}

int main()
{
    const char* iniad = "INIAD Toyo";
    printf("strlen(iniad) = %lu\n", strlen(iniad));
    printf("my_strlen(iniad) = %lu\n", my_strlen(iniad));

    char s[20];
    my_strcpy(s,"iniad");
    printf("%s\n", s);
    return 0;
}