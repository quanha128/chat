#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* my_strstr(const char* haystack, const char* needle)
{
    int flag = 0;
    int i =0;
LOOP: for (i; i<strlen(haystack); i++){
        if (haystack[i] == needle[0]){
            for (int j=1; j<strlen(needle); j++){
                if (haystack[i+1] == needle[j]){
                    i++;
                    if (j==strlen(needle)-1){
                        flag = 1;
                        return &haystack[i-j];
                    }
                }
                else {
                    i++;
                    goto LOOP;
                }
            }
        }
    }
    if (flag == 0) return NULL;
}

int main ()
{
    char haystack[] ="This is a simple string";
    char * pch, pch2;
    pch = my_strstr(haystack,"simple");
    printf("%p\n",pch);
    strncpy(pch,"sample",6);
    puts(haystack);
    pch2 = my_strstr(haystack,"simple");
    printf("%p\n",pch2);
    return 0;
}