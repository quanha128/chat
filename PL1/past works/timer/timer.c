#include <stdio.h>
#include <unistd.h>

int main()
{
    int seconds;
    printf("seconds = ");
    scanf("%d", &seconds);
    while (seconds>0)
    {
        printf("%d\n", seconds);
        seconds-=1;
        sleep(1);
    }
    return 0;
}