#include <stdio.h>

int jst_to_est(int jst)
{
    int est = jst-14;
    if (est <0)
        est +=24;
    return est;
}

int main()
{
    int hour;
    printf("Time in Japan? ");
    scanf("%d", &hour);
    printf("it is %d in New York\n", jst_to_est(hour));
    return 0;
}