#include <stdio.h>
#include <stdlib.h>
#include "bigint.h"

int main(){
    bigint result;
    bigint_set_int(&result, 1);
    for(int i = 1; i <= 50; i++){
        bigint a;
        bigint_set_int(&a, i);
        bigint_mul(&result, &a);
        printf("%d! = ", i);
        bigint_print(&result);
    }
}