#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* rand = fopen("/dev/random", "rb");
    int cnt=0;
    char psw[8];
    char data;
    for (;;){
        fread(&data, 1, 1, rand);
        if (48<=data&&data<=57 || 65<=data&&data<=90 || 97<=data&&data<=122) {
            psw[cnt] = data;
            cnt++;
        }
        if (cnt==8) break;
    }
    printf("%s\n", psw);
    return 0;
}