#include <stdio.h>
#include <omp.h>
#include <math.h>
#include <stdlib.h>

void nowait_example(int n, int m, float *a, float *b, float *y){
    int i;
    #pragma omp parallel
    {
        #pragma omp for nowait
        for(i = 1; i < n; i++){
            b[i] = (a[i] + a[i-1]) / 2.0;
        }
        #pragma omp for nowait
        for(i = 1; i < m; i++)
            y[i] = sqrt(b[i-1]);
    }
}

int main(){
    int n = 30;
    int m = 30;
    float a[n];
    float b[m];
    float y[m];
    for(int i = 0; i < n; i++) a[i] = 2;
    for(int i = 1; i < n; i++){
        printf("%f ", a[i]);
    }
    printf("---\n");
    nowait_example(n, m, a, b, y);
    for(int i = 1; i < n; i++){
        printf("%f ", b[i]);
    }
    printf("---\n");
    for(int i = 1; i < m; i++){
        printf("%f ", y[i]);
    }
}