#include <stdio.h>

void sieve(int n)
{
    int arr[n];
    arr[0] = 0; arr[1]= 0;
    for (int i=2; i<=n; i++){
        arr[i] = i;
    }
    for (int i=2; i*i<=n; i++){
        if (arr[i]!=0){
            for (int j=i*i; j<=n; j+=i)
                arr[j] = 0;
        }
    }
    for (int i=2; i<=n; i++){
        if (arr[i]!=0) printf("%4d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    sieve(1000000);
    return 0;
}
