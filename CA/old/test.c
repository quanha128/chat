#include <stdio.h>
#include <string.h>

int main() {
    char str[256] = "It's a Small World, isn't it?";
    for (int i=0; i<strlen(str); i++) {
        if (str[i] > 0x5a && str[i] < 0x41) printf("%c", str[i]);
        else { 
            str[i] += 32;
            printf("%c", str[i]);
        }
    }
    printf("\n");
    printf("%d\n", '0');
    return 0;
}