#include <stdio.h>

int main () {
    char buf[123];
    int idx = 0;
    buf[idx] = "abc";
    idx += sizeof("abc");
    buf[idx] = '\0';
    printf("%s\n", buf);
    return 0;
}