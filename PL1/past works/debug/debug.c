#include <stdio.h>

unsigned int fib(unsigned int n)
{
    unsigned int f[n+1];
    f[0] = 0; f[1] = 1;
    
    for (unsigned int i = 2; i <= n; i++){
        f[i] = f[i-1] + f[i-2];
    }

    return f[n];
}

int main ()
{
    printf("fib(40) = %u\n", fib(40));
    return 0;
}