#include <stdio.h>

int test56(__uint32_t num) {
    if ((num & (1<<5)) && (num & (1<<6))) {
        return 1;
    }
    else return 0;
}

int main() {
    // bit 5 and bit 6 are 1
    __uint32_t num1 = 96;
    printf("%d\n", test56(num1));

    // bit 5 and bit 6 are 0
    __uint32_t num2 = 95;
    printf("%d\n", test56(num2));
    return 0;
}