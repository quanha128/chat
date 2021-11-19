#include <stdio.h>
extern double integral(double x1, double x2, double(*f)(double));

static double f(double x) { return 1/(x*x+1); }

int main()
{
    double pi = integral(0.0,1.0,&f)*4;
    printf("%f\n",pi);
    return 0;
}