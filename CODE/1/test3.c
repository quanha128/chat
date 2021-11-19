#include <stdio.h>

int main() {
    long long m=0, a=0, r=0, c=0, h=0;
    int num;
    long long D[5];
    char name[100];
    scanf("%d", &num);
    for (int i=0; i<num; i++) {
        scanf("%s", name);
        if (name[0] == 'M') m++;
        if (name[0] == 'A') a++;
        if (name[0] == 'R') r++;
        if (name[0] == 'C') c++;
        if (name[0] == 'H') h++;
    }

    D[0]=m, D[1]=a, D[2]=r, D[3]=c, D[4]=h;

    int P[10] = {0,0,0,0,0,0,1,1,1,2};
    int Q[10] = {1,1,1,2,2,3,2,2,3,3};
    int R[10] = {2,3,4,3,4,4,3,4,4,4};

    int sum=0;
    for (int i=0; i<10; i++) {
        sum += D[P[i]] * D[Q[i]] * D[R[i]];
    }
    printf("%d\n", sum);
}