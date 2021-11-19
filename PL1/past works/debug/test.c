#include <stdio.h>

int main()
{
    int n,sum=0,i=1;
    printf("n= ");
    scanf("%d",&n);
    while (i<=n)
    {
        sum+=i*i*i*i;
        i++;
    }
    printf("%d\n",sum);
}