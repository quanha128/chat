#include <stdio.h>

extern int sum(int n, int m);

int main()
{
    printf("sum(50,100) = %d\n", sum(50,100));
    return 0;
}
