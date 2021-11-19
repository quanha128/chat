#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_binary(u_int32_t u){
    int s[32];
    int n = u, i = 0;
    for (i; i<32; i++){
        s[i] = n%2;
        n /= 2;
    }
    for (i=i-1; i>=0; i--){
        printf("%d",s[i]);
    }
    printf("\n");
}

int main()
{
    union floatval {
        float f;
        u_int32_t u;
    } v;
    v.f = 0.13579;
    print_binary(v.u);
    return 0;
}