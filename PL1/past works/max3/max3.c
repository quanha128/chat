#include <stdio.h>

int main ()
{
    int x, y, z, maxv;
    printf("x? ");
    scanf("%d", &x);
    printf("y? ");
    scanf("%d", &y);
    printf("z? ");
    scanf("%d", &z);
    maxv = x;
    if (maxv<y) maxv=y;
    if (maxv<z) maxv=z;
    printf("max value is %d\n", maxv);
    return 0;

}