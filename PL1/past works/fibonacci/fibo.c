#include <stdio.h>

int fib(int n)
{
    int a=0, b=1, c, i=1;
    if (n==0)
        return a;
    if (n==1)
        return b;
    while (i<n) {
        c=a+b;
        a=b;
        b=c;
        i+=1;
    }
    return c;
}

int main() 
{ 
    int n = 4000; 
    printf("%d", fib(n));
    return 0; 
} 