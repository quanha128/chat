#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if (argc != 2){
        fprintf(stderr, "You need to input an hour\n");
        return 1;
    }
    int hour = atoi(argv[1]);
    if (hour>=5 && hour<=10) printf("%s\n", "Good morning");
    else if (hour>=11 && hour<=17) printf("%s\n", "Hello");
    else if (hour>=18 && hour<=20) printf("%s\n", "Good evening");
    else printf("%s\n", "Good night");
    return 0;
}