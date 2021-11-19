/*
    $ gcc -Wall div3.c -lgmp -o div3
    $ ./div3
*/

#include <stdio.h>
#include <gmp.h>

int main()
{
    /* Set precision to 1000 bits */
    mpf_set_default_prec(10000);
    
    mpf_t a, b, c;
    mpf_init(a);
    mpf_init(b);
    mpf_init(c);

    mpf_set_si(a, 10); // a = 10;
    mpf_set_si(b, 3); // b = 3;
    mpf_div(c, a, b); // c = a / b;

    gmp_printf("10 / 3 = %.1000Ff\n", c);
    gmp_printf("%Ff\n", a);

    mpf_clear(c);
    mpf_clear(b);
    mpf_clear(a);
    return 0;
}
