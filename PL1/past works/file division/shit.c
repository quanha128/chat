#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BASE 10000

typedef struct {
    // number of digits in 10000-ary base
    int n;
    // 10000-ary array
    int* digits;
} bigint;

void bigint_set_int(bigint* x, int v){
    // maximum is 64 bit, so we have 20 numbers
    x->digits = (int*) malloc(20 * sizeof(int));
    if(!x->digits){
        fprintf(stderr, "Error: Cannot malloc for digits!\n");
        return;
    }
    int idx = 0;
    while(v != 0){
        x->digits[idx++] = v % BASE;
        v /= BASE;
    }
    x->n = idx;
}

void bigint_set_str(bigint*x, char* number){
    int l = strlen(number);
    x->digits = (int*) malloc((l / 4 + 1) * sizeof(int));
    if(!x->digits){
        fprintf(stderr, "Error: Cannot malloc for digits!\n");
        return;
    }
    // in case strlen < 4, or number < 10000
    int idx = (l - 4 >= 0 ? l - 4 : 0);
    x->n = 0;
    while(idx >= 0){
        x->digits[x->n ++] = atoi(number + idx);
        // set up for next atoi
        number[idx] = '\x00';
        // same reason with above
        idx = (l - 4 >= 0 ? l - 4 : 0);
    }
}

void bigint_add(bigint* x, bigint* const a){
    int maxLen = (x->n >= a->n ? x->n : a->n);
    // x + a might have carries
    int* newDigits = (int*) malloc((maxLen + 1) * sizeof(int));
    if(!newDigits){
        fprintf(stderr, "Error: Cannot malloc for digits!\n");
        return;
    }
    int carry = 0;
    // reverse add
    for(int i = 0; i < maxLen + 1; i++){
        int xDigit = (i < x->n ? x->digits[i] : 0);
        int aDigit = (i < a->n ? a->digits[i] : 0);
        newDigits[i] = xDigit + aDigit + carry;
        // if there is carrry
        carry = newDigits[i] / BASE;
        newDigits[i] %= BASE;
    }
    if(carry == 0){
        int* copy = (int*) malloc(maxLen * sizeof(int));
        
        for(int i = 0; i < maxLen; i++){
            copy[i] = newDigits[i];
        }
        free(x->digits);
        x->digits = copy;
        x->n = maxLen;
    } else{
        // add carry to first digit
        newDigits[maxLen] = carry;
        free(x->digits);
        // replace new result
        x->digits = newDigits;
        x->n = maxLen + 1;
    }
}

void bigint_mul(bigint* x, bigint* const a){
    long long maxLen = x->n + a->n + 1;
    int* newDigits = (int*) calloc(maxLen, sizeof(int));
    if(!newDigits){
        fprintf(stderr, "Error: Cannot calloc for digits!\n");
        return;
    }
    // x digits index 
    for(int xi = 0; xi < x->n; xi++){
        // xi * a->digits
        for(int ai = 0; ai < a->n; ai++){
            newDigits[xi + ai] = newDigits[xi + ai] + x->digits[xi] * a->digits[ai];
            newDigits[xi + ai + 1] += newDigits[xi + ai] / BASE;
            newDigits[xi + ai] %= BASE;
        }
        newDigits[xi + a->n + 1] += newDigits[xi + a->n] / BASE;
        newDigits[xi + a->n] %= BASE;
    }
    // leftover carry 
    x->n = maxLen;
    // find true length of x by looping back until a non-zero number is there
    for(int i = maxLen - 1; i >= 0; i--){
        int crtDigit = newDigits[i];
        if(crtDigit != 0) break;
        x->n --;
    }
    // in case malloc fail, we create new poitners to copy
    int* copy = (int*) malloc(x->n * sizeof(int));
    if(!copy){
        free(x->digits);
        fprintf(stderr, "Error: Cannot malloc for copying digits!\n");
        return;
    }
    for(int i = 0; i < x->n;i++){
        copy[i] = newDigits[i];
    }
    free(x->digits);
    x->digits = copy;
}

void bigint_print(bigint* x){
    for(int i = x->n - 1; i >= 0; i--){
        printf((i == x->n - 1 ? "%d" : "%04d"), x->digits[i]);
    }
}

int main(){
    bigint fact;
    bigint_set_int(&fact, 1);
    for(int i = 1; i <= 50; i++){
        bigint I;
        bigint_set_int(&I, i);
        bigint_mul(&fact, &I);
        printf("%d! = ", i);
        bigint_print(&fact);
        printf("\n");
    }
}