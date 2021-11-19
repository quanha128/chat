#include <stdio.h>

void print_decimal(unsigned long v) {
    printf("v = %d\n", v);
}

void print_hexadecimal(unsigned long v) {
    printf("v = 0x%x\n", v);
}

void print_binary(unsigned long v) {
    unsigned i; 
    for (i = 1 << 31; i > 0; i = i / 2) 
        (v & i)? printf("1"): printf("0");
    printf("\n"); 
}

int main() {
    print_decimal(129);
    print_hexadecimal(129);
    print_binary(129);
    return 0;
}