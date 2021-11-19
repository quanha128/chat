#include <stdio.h>

int main() {
    int A, B;
    int res = 1;
    scanf("%d", &A);
    scanf("%d", &B);
    for (int i=0; i<A-B; i++) {
        res *= 32;
    }
    printf("%d\n", res);
}