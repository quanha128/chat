#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct fraction {
    int numer;
    int denom;
};

typedef struct fraction frac;

void fraction_print(frac a)
{
    printf("%d/%d\n", a.numer, a.denom);
}

void fraction_mul(frac* result, frac* a, frac* b)
{
    result -> numer = a -> numer * b -> numer;
    result -> denom = a -> denom * b -> denom;
}

void fraction_add(frac* result, frac* a, frac* b)
{
    result->numer = a->numer * b->denom + b->numer * a->denom;
    result->denom = a->denom * b->denom;
    if (result->numer < result->denom){
        for (int i=result->numer; i>1; i--){
            if (result->numer%i==0 && result->denom%i==0){
                result->numer /= i;
                result->denom /= i;
            }
        }
    }
    else{
        for (int i=result->denom; i>1; i--){
            if (result->numer%i==0 && result->denom%i==0){
                result->numer /= i;
                result->denom /= i;
            }
        }
    }
}

int main()
{
    frac a = {.numer = 7, .denom = 3};
    frac b = {.numer = 2, .denom = 5};
    frac c = {.numer = 5, .denom = 3};
    frac d = {.numer = 1, .denom = 6};
    frac result1;
    frac result2;

    fraction_mul(&result1, &a, &b);
    fraction_print(result1);

    fraction_add(&result2, &c, &d);
    fraction_print(result2);
}