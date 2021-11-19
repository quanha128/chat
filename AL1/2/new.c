#include <stdio.h>

int check_swap(int* a, int* b){
    if (*a < *b) {
        int m = *a;
        *a = *b;
        *b = m;
        return 1;
    }
    else return 0;
}

int main() {
    int a=3, b=5;
    printf("%d\n",check_swap(&a,&b));
    printf("a=%d, b=%d\n", a, b);
    return 0;
}