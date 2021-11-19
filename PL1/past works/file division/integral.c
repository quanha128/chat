/*
 * Calculation of Integrals
 */

double integral(double x1, double x2, double (*f)(double))
{
    const int n = 1000;

    double dx = (x2 - x1) / n;
    double sum = 0;
        
    for (int i = 0; i < n; i++) {
        double x = x1 + dx * i;
        sum += f(x) * dx;
    }

    return sum;
}
