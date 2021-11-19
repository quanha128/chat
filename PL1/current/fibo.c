#include <stdio.h>

void matmul(int a[2][2], int b[2][2]) {
    int mul[3][3]; 
    for (int i = 0; i < 2; i++) { 
        for (int j = 0; j < 2; j++) { 
            mul[i][j] = 0; 
            for (int k = 0; k < 2; k++) 
                mul[i][j] += a[i][k]*b[k][j]; 
        } 
    }

    for (int i=0; i<2; i++) 
        for (int j=0; j<2; j++) 
            a[i][j] = mul[i][j];
} 

int matpower(int m[2][2], int n){
    int temp[2][2] = {{1,1},{1,0}};

    if (n==1) 
        return m[0][0] + m[0][1];
    matpower(m, n/2);
    matmul(m, m);

    if (n%2 != 0) 
        matmul(m, temp); 

    return m[0][0] + m[0][1] ; 
} 

int fibo(int n){
    int a[2][2] = {{1,1},{1,0}};
    if (n==0) return 0;
    if  (n==1 || n==2) return 1;
    return matpower(a, n);
}

int main(){
    printf("%d\n", fibo(45));
    return 0;
}