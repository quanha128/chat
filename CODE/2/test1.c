#include <stdio.h>

int main() {
    int N;
    char str[100];
    scanf("%d", &N);
    scanf("%s", str);
    if (str[N-1] == 'o') printf("Yes\n");
    else printf("No\n");
}