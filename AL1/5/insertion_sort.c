/* insertion_sort.c */

#include "sort.h"

void sort(int *list, int length) {
    for(int i = 1; i < length; i++) {
        int target = list[i];
        int j;
        for(j = i - 1; j >= 0; j--) {
            if(target < list[j]) {
                list[j + 1] = list[j];
            } else {
                break;
            }
        }
        list[j + 1] = target;
        for (int k=0; k<length; k++) {
            if (k==length-1)
                printf("%d", list[k]);
            else printf("%d,", list[k]);
        }
        printf("\n");
    }
}