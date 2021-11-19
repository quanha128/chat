#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void* divide_name(char* name, char** first, char** last)
{
    int i=0;
    for(i; name[i]!=' '; i++){
        first[i] = name[i];
    }
    i++;
    for(i; name[i]!='\0'; i++){
        last[i] = name[i];
    }
}

int main() 
{
    char* f;
    char* l;
    divide_name('Enryo Inoue', &f, &l);
    printf("%s\n",&f);
    printf("%s\n",&l);
}

