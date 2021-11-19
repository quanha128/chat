#include <stdio.h>
#include <omp.h>

int main() {
    // a)
    // #pragma omp parallel
    // for (int j=0; j<5; j++) {
    //     printf("Hello\n");
    // }

    // b)
    #pragma omp parallel for
    for (int j=0; j<5; j++) {
        printf("Hello\n");
    }
}