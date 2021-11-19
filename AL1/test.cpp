#include <iostream>
using namespace std;

int find_pivot(int arr[], int start, int end, int *pivot) {
    *pivot = arr[start];
    for (int i=start+1; i<end; i++) {
        if (arr[i] > *pivot) {
            *pivot = arr[i];
            return 1;
        } else {
            return 1;
        }
    }
    return 0;
}

int partition(int arr[], int left, int right, int pivot) {
    while(1) {
        while(arr[left] < pivot) left++;
        while(arr[right] > pivot) right--;
        if (left >= right) break;

        int tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;

        left ++;
        right --;
    }
    return left;
}

void quicksort(int arr[], int start, int end) {
    int pivot;
    if (!find_pivot(arr, start, end, &pivot)) return;

    int p = partition(arr, start, end, pivot);

    quicksort(arr, start, p-1);
    quicksort(arr, p, end);
}

int main() {
    int arr[] = {5,2,7,8,6,4,9,1,3};
    int length = sizeof(arr) / sizeof(int);

    cout << "Before: ";
    for (int i=0; i<length; i++) {
        if (i < length-1) cout << arr[i] << " ";
        else cout << arr[i] << "\n";
    }

    quicksort(arr, 0, length);

    cout << "After: ";
    for (int i=0; i<length; i++) {
        if (i < length-1) cout << arr[i] << " ";
        else cout << arr[i] << "\n";
    }
}