#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* fp;
    fp = fopen("./sonnet.txt","r");
    char s[128];
    int cnt = 0;
    while (fgets(s, sizeof(s), fp)){
        cnt++;
    }
    printf("%d\n",cnt);
    fclose(fp);
    return 0;
}