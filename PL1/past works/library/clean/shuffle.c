#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_range(int min, int max)
{
    srand((unsigned int)time(0));
    return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}

void shuffle(void* arr, size_t size, size_t n)
{
    char* A = arr;
    char temp[size];
    for (int i=n-1; i>=0; i--){
        int select = rand_range(0,i-1);
        if (i != select){
            for (int j=0; j<size; j++){
                temp[j] = *(A+i*size+j);
                *(A+i*size+j) = *(A+select*size+j);
                *(A+select*size+j) = temp[j];
            }
        }
    }
}

int main(int argc, char* argv[])
{
    if (argc != 2){
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }
    FILE* fp = fopen(argv[1], "r");
    if(!fp){
        perror("ERROR");
        return 1;
    }

    char* lines[128];
    int i = 0;

    while (1){
        char* s = (char*)(malloc(128));
        s = fgets(s, 128, fp);
        lines[i] = s;
        if(!lines[i]) break;
        i++;
    }

    shuffle(lines, sizeof(lines[0]), i);

    for (int j=0; j<i; j++){
        printf("%s", lines[j]);
    }
    printf("\n");

    fclose(fp);
    return 0;
}