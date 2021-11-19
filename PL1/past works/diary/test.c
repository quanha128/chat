#include <stdio.h>
#include <stdlib.h>

int halfadder(int A, int B, int* C)
{
    int R;
    *C = A & B;
    return R = (~A & B) | (A & ~B);
}

int main()
{
    int C;
    halfadder(0,0,&C);
    printf("C=%d\n",C);
    printf("R=%d\n",halfadder(0,0,&C));

    halfadder(0,1,&C);
    printf("C=%d\n",C);
    printf("R=%d\n",halfadder(0,1,&C));

    halfadder(1,0,&C);
    printf("C=%d\n",C);
    printf("R=%d\n",halfadder(1,0,&C));

    halfadder(1,1,&C);
    printf("C=%d\n",C);
    printf("R=%d\n",halfadder(1,1,&C));
}