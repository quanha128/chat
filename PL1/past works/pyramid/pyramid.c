#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void pyramid(int n)
{
    int cnt = 2, s=n-1;
    for (int i=0; i<n; i++){
        for (int j=0; j<s; j++){
            printf(" ");
        }
        s--;
        for (int k=0; k<cnt; k++){
            printf("#");
        }
        cnt+=2;
        printf("\n");
    }
}

int main()
{
    pyramid(7);
    return 0;
}