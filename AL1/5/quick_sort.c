/* quick_sort.c */

#include "sort.h"
#include <stdio.h>

int find_pivot(int *list, int start, int end, int *pivot) {
    int first = list[start];
    for(int i = start + 1; i <= end; i++) {
        if(first < list[i]) {
            *pivot = list[i];
            printf("Pivot: %d\n", *pivot);
            return 1;
        } else if(first > list[i]) {
            *pivot = first;
            printf("Pivot: %d\n", *pivot);
            return 1;
        }
    }
    return 0;
}

int partition(int *list, int left, int right, int pivot) {
    for(;;) {
        while(list[left] < pivot) {
            left++;
        }
        while(list[right] >= pivot) {
            right--;
        }
        if(left >= right) {
            break;
        }
        
        int tmp = list[left];
        list[left] = list[right];
        list[right] = tmp;
        printf("swap: %d, %d\n", list[left], list[right]);
        left++;
        right--;
    }

    return left;
}

void quick_sort(int *list, int start, int end) {
    int pivot;
    if(! find_pivot(list, start, end, &pivot)) {
        return;
    }

    int p = partition(list, start, end, pivot);

    quick_sort(list, start, p - 1);
    quick_sort(list, p, end);
    
}

void sort(int *list, int length) {
    quick_sort(list, 0, length - 1);
}
