#include <stdio.h>
#include <stdint.h>

uint32_t rotate_left(const uint32_t x, const unsigned int n)
{
    return x << n | x >> (32-n);
}

void bin(unsigned n) 
{ 
    unsigned i; 
    for (i = 1 << 31; i > 0; i = i / 2) 
        (n & i)? printf("1"): printf("0");
    printf("\n"); 
}

int count_ones(unsigned n) 
{ 
    unsigned i;
    int count = 0;
    for (i = 1 << 31; i > 0; i = i / 2) 
        if (n & i) count++;
    return count;
}

int main()
{
    uint32_t x = 0xdeadbeef, y = 0xcafecafe;
    bin(x);
    printf("%d\n",count_ones(x));
    // bin(rotate_left(x, 5));
    printf("%d\n",count_ones(y));
    return 0;
}