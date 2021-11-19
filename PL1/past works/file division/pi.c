#include <stdio.h>
#include <gmp.h>

int main()

{
    int k=1;
    mpf_set_default_prec(10000);

    mpf_t a, x,
          err, res, last,
          i1, i5, i239,
          frac1, frac2, frac3,
          num1,
          den1, den2, den3,
          sub, machin, marg, abs;
    
    //initialize all vars
    mpf_init(a);mpf_init(x);mpf_init(err);mpf_init(last);mpf_init(res);
    mpf_init(i1);mpf_init(i5);mpf_init(i239);mpf_init(frac1);mpf_init(frac2);
    mpf_init(frac3);mpf_init(num1);mpf_init(den1);mpf_init(den2);mpf_init(den3);
    mpf_init(sub);mpf_init(machin);mpf_init(marg);mpf_init(abs);

    //margin of error = 1*10^(-1000)
    mpf_set_ui(a, 10);
    mpf_pow_ui(x, a, 1000);
    mpf_ui_div(err, 1, x);

    do{
        // calc frac1
        mpf_set_si(i1, -1);
        mpf_pow_ui(num1, i1, k-1);
        mpf_set_ui(den1, 2*k-1);
        mpf_div(frac1, num1, den1);

        //calc frac2
        mpf_set_ui(i5, 5);
        mpf_pow_ui(den2, i5, 2*k-1);
        mpf_ui_div(frac2, 16, den2);

        //calc frac3
        mpf_set_ui(i239, 239);
        mpf_pow_ui(den3, i239, 2*k-1);
        mpf_ui_div(frac3, 4, den3);

        //calc sum
        mpf_sub(sub, frac2, frac3);
        mpf_mul(machin, frac1, sub);

        //calc sum when check with error
        mpf_set(last, res);
        mpf_add(res, res, machin);

        //calc error
        mpf_sub(marg, res, last);
        mpf_abs(abs, marg);

        k++;
    } while (mpf_cmp(abs, err)>0); //keep calc while error > margin of error

    //clean vars
    mpf_clear(a);mpf_clear(x);mpf_clear(err);mpf_clear(last);
    mpf_clear(i1);mpf_clear(i5);mpf_clear(i239);mpf_clear(frac1);mpf_clear(frac2);
    mpf_clear(frac3);mpf_clear(num1);mpf_clear(den1);mpf_clear(den2);mpf_clear(den3);
    mpf_clear(sub);mpf_clear(machin);mpf_clear(marg);mpf_clear(abs);

    printf("k = %d\n", k);
    gmp_printf("pi = %.1000Ff\n", res);

    mpf_clear(res);
    return 0;
}