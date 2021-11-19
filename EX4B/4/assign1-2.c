#include <stdio.h>
#include <omp.h>

void work1() {}
void work2() {}

void single_example() {
    #pragma omp parallel
    {
    #pragma omp master
        printf("Thread#%d Beginning work1\n", omp_get_thread_num());
        work1();
    #pragma omp master
        printf("Thread#%d Finishing work1\n", omp_get_thread_num());
    #pragma omp master
    printf("Thread#%d Finished work1 and beginning work2\n", omp_get_thread_num());
    work2();
    }
}

int main() {
    single_example();
    return 0;
}