#include <stdio.h>

unsigned int gcd(unsigned int a, unsigned int b) {
    if (a<b){
        int m = a;
        a = b;
        b = m;
    }
    while (1)
    {
        int r = a%b;
        if (r==0) return b;
        else {
            a=b;
            b=r;
        }
    }
}

int main(int argc, char* argv[]) {
    unsigned int a, b;
    printf("Input a:");
    scanf("%d", &a);
    printf("Input b:");
    scanf("%d", &b);

    printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));
    
    return 0;
}