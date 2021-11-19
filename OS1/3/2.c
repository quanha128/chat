#include <stdio.h>
#include <ctype.h>

int main(){
    char letter;
    int alp[26]={0};
    for (;;) {
        letter = fgetc(stdin);
        if (letter == EOF) break;
        if (isalpha(letter)==0) continue;
        if (letter < 'a') alp[letter+32 - 'a'] ++;
        else alp[letter - 'a'] ++;
    }
    for (char i='a'; i<='z'; i++) {
        printf("%c: %d\n", i, alp[i-'a']);
    }
    return 0;
}