def hogeSort(arr):
    for index in range(len(arr)):
        key = arr[index]
        while (index-1>=0 and arr[index-1]>key):
            arr[index] = arr[index-1]
            index = index - 1
        arr[index] = key

if __name__ == '__main__':
    ls = list(map(int, input().split()))
    hogeSort(ls)
    print(ls)