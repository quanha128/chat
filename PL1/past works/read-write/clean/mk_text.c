#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* fp;
    fp = fopen("./sonnet.txt","w");
    const char* lines[] = {
        "Shall I compare thee to summer's day?\n",
        "Thou art more lovely and more temperate:\n",
        "Rough winds do shake the darling buds of May,\n",
        "And summer's lease hath all too short a date:\n",
    };
    for (int i=0; i < sizeof(lines)/sizeof(lines[0]); i++)
        fputs(lines[i], fp);
    fclose(fp);
    return 0;
}