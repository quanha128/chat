#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char* argv[]) {
    int n;
    if (argc > 2) {
        fprintf(stderr, "Invalid argument\n");
        return 0;
    } else if(argc < 2) {
        n = 64;
    } else n = atoi(argv[1]);

    int **A = (int**)malloc(n*sizeof(int*));
    int **B = (int**)malloc(n*sizeof(int*));
    int **C = (int**)malloc(n*sizeof(int*));

    for (int i=0; i<n; i++) {
        A[i] = (int*)malloc(n*sizeof(int));
        B[i] = (int*)malloc(n*sizeof(int));
        C[i] = (int*)malloc(n*sizeof(int));
    }

    // initialize matrix
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            A[i][j] = rand();
            B[i][j] = rand();
        }
    }

    // compute C = A*B
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            C[i][j] = 0;
            for (int k=0; k<n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    //free
    free(A);
    free(B);
    free(C);

    return 0;
}