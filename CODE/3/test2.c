#include <stdio.h>
#include <string.h>

int main() {
    char S[200];
    char T[200];
    scanf("%s", S);
    scanf("%s", T);
    if (strcmp(S, T) == 0) printf("Yes\n");
    else {
        for (int i=0; i<(strlen(S)-1); i++) {
            char temp[200];
            strcpy(temp, S);
            temp[i] = S[i+1];
            temp[i+1] = S[i];
            if (strcmp(temp, T) == 0) {
                printf("Yes\n");
                return 0;
            }
        }
        printf("No\n");
        return 0;
    }
}