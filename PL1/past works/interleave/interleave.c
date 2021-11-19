#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* interleave(char* d, const char a[], const char b[])
{
    int maxlen = strlen(a);
    int minlen = strlen(b);

    if (strlen(a) < strlen(b)){
        maxlen = strlen(b);
        minlen = strlen(a);
    }
    int id=0;
    int i=0;
    for (i; i < minlen; i++){
        d[id] = a[i];
        d[id + 1] = b[i];
        id+=2;
    }
    for (i; i<maxlen; i++){
        if (maxlen == strlen(a)) {
            d[id] = a[i];
            id++;
        }
        if (maxlen == strlen(b)) {
            d[id] = b[i];
            id++;
        }
    }
    d[id+1] = '\0';
    return d;
}

int main()
{
    char a[] = "Toyo";
    char b[] = "University";
    char d[strlen(a) + strlen(b) + 1];
    printf("%s\n", interleave(d,a,b));
}