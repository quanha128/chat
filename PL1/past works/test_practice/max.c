#include <stdio.h>

int max(int arr[], int n)
{
    int max = arr[0];
    for (int i=1; i<n; i++){
        if (arr[i]>max) max = arr[i];
    }
    return max;
}

int main() {
    int arr[] = {1, 4, 3, 7, 4, 9};

    printf("max(arr, 5) = %d\n", max(arr, 5));
    printf("max(arr, 6) = %d\n", max(arr, 6));
    return 0;
}