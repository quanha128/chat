#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double quad_ed (double a, double b, double c) {
    double temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8;
    temp1 = b * b;
    temp2 = 4 * a;
    temp3 = temp1 * c;
    temp4 = temp1 - temp3;
    temp5 = sqrt(temp4);
    temp6 = temp5 - b;
    temp7 = 2 * a;
    temp8 = temp6 / temp7;
    return temp8;
}

int fact(int n0)
{
  int result0 = 1;
  int i0 = n0;
  int i1, i2, result1, result2;
  
  while(i2 = phi(i0, i1), result2 = phi(result0, result1), i2>0) {
    result1 = result2 * i2;
    i1 = i2 - 1;
  }

  return result2;
}

int foo (int %edi, int %esi) {
    int %edi = %edi - 1;
    Save(b, %esi);
    int %eax = abs(%edi);
    Restore(b, %edi);
    int %edi = %edi - 1;
    Save(temp2, %eax);
    int %eax = abs(%edi);
    Restore(temp2, %X);
    int %eax = %eax + %X;
    return %eax;
}