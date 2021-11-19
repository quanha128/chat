#include <stdio.h>

int main () {
    int num;
    char inp[200];
    scanf("%d", &num);
    for (int i=0; i<num; i++) {
        scanf("%c", inp);
        if (inp[0] == 'Y') {
            printf("Four\n");
            return 0;
        }
    }
    printf("Three\n");
    return 0;
}