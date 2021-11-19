#include <stdio.h>


int main(void){
    int n;
    scanf("%d",&n);
    int sum=0;
    for (int i = 1; i<=n; i++){
        int count=0;
        for (int j=1;j<=i; j++){
            if (i%j==0)
                count ++;
        }
        sum += count * i;
    }
    printf("%d\n", sum);
}