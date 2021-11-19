#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char* normalize(const char* s)
{
    char* copy = (char*)malloc(sizeof(char)*strlen(s)+1);
    int pos = 0;
    for (int i=0; s[i]!='\0'; i++){
        if (isalpha(s[i])){
            copy[i-pos] = s[i];
            if (isupper(copy[i-pos]))
                copy[i-pos] = tolower(copy[i-pos]);
        }
        else pos++;
    }
    return copy;
}

int main() {
    const char* s = "Information Networking for Innovation and Design!";

    printf("normalize(s) = %s\n", normalize(s));
    printf("s = %s\n", s);
    return 0;
}