#include <stdio.h>

void main() {
    int N;
    char S[1000];
    char T[1000];
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%s", S[i]);
    }
    printf("%s\n\n\n", S);

    // for (int i=0; i<N; i++) {
    //     scanf("%s", T);
    // }
    // printf("%s\n", T);
}