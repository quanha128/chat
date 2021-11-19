#include <stdio.h>

int fib(int n)
{
    int c, i=1;
    if (n==0)
        return 0;
    if (n==1)
        return 1;
    while (i<n) {
        c=fib(n-2)+fib(n-1);
        i+=1;
    }
    return c;
}

int main () {
    int n=40;
    printf("value=%d", fib(n));
    return 0;
}