#include <stdio.h>

// Ascending sort
void aSort(int *a, int *b)
{
    int tmp;
    if (*a > *b){
        tmp = *a;
        *a = *b;
        *b = tmp;
    }
}

int main()
{
    int x, y;

    printf("x = ");
    scanf("%d", &x);

    printf("y = ");
    scanf("%d", &y);

    aSort(&x, &y);
    printf("After asending sort: x = %d, y = %d \n", x, y);

    return 0;
}
