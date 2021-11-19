#include <stdio.h>

int JST_to_EST(int jst)
{
    int est= jst-14;
    if (est<0)
        est+=24;
    return est;
}

int main()
{
    int hour;
    printf("Time in Japan (0-23)? ");
    scanf("%d", &hour);
    if (0>hour || hour>23)
        printf("ERROR: please input time correctly\n");
    else printf("It is %d in NY\n", JST_to_EST(hour));
    return 0;
}