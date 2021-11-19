#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    int n;
    int* digit;
} bigint;

void bigint_set_int(bigint* x, int v)
{
    char* s = (char*)malloc(sizeof(char)*20);
    sprintf(s, "%d", v);
    int len = strlen(s);
    x->digit = malloc(sizeof(int)*len);
    x->n = len;
    for (int i=0; i<len; i++){
        x->digit[i] = (s[len-1-i]-48);
    }
    free(s);
}

void bigint_add(bigint* x, bigint* a)
{
    int maxlen, carry = 0;;
    bigint hoge;
    if (x->n > a->n){
        maxlen = x->n;
    }
    else{
        maxlen = a->n;
    }
    hoge.digit = malloc((maxlen+1)*(sizeof(int)));
    for (int i=0; i<maxlen+1; i++){
        int X = (i < x->n ? x->digit[i] : 0);
        int A = (i < a->n ? a->digit[i] : 0);
        hoge.digit[i] += X + A + carry;
        carry = hoge.digit[i] / 10;
        hoge.digit[i] = hoge.digit[i] % 10;
    }
    if(carry == 0){
        int* copy = malloc(maxlen * sizeof(int));
        
        for(int i = 0; i < maxlen; i++){
            copy[i] = hoge.digit[i];
        }
        free(x->digit);
        x->digit = copy;
        x->n = maxlen;
    }
    else{
        hoge.digit[maxlen] = carry;
        free(x->digit);
        x->digit = hoge.digit;
        x->n = maxlen + 1;
    }
}

void bigint_mul(bigint* x, bigint* a)
{
    bigint hoge;
    hoge.digit = calloc(x->n + a->n + 1,(sizeof(int)));
    for (int i=0; i<x->n; i++){
        for (int j=0; j<a->n; j++){
            hoge.digit[i+j] += x->digit[i] * a->digit[j];
            if (hoge.digit[i+j] > 9){
                hoge.digit[i+j+1] += hoge.digit[i+j] / 10;
                hoge.digit[i+j] = hoge.digit[i+j] % 10;
            }
        }
    }
    x->n = x->n + a->n + 1;
    for(int i= x->n - 1; i >= 0; i--){
        if(hoge.digit[i] != 0) break;
        x->n --;
    }
    int* copy = malloc(x->n * sizeof(int));
    for(int i=0; i < x->n; i++){
        copy[i] = hoge.digit[i];
    }
    free(x->digit);
    x->digit = copy;
}

void bigint_print(bigint* x)
{
    for (int i=x->n-1; i>=0; i--){
        printf("%d", x->digit[i]);
    }
    printf("\n");
}