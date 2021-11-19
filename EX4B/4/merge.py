def merge(left, right):
    leftIndex, rightIndex = 0,0
    ret = []
    while (leftIndex<len(left) and rightIndex<len(right)):
        if left[leftIndex] <= right[rightIndex]:
            ret.append(left[leftIndex])
            leftIndex += 1
        else:
            ret.append(right[rightIndex])
            rightIndex += 1
    for lidx in range(leftIndex, len(left)):
        ret.append(left[lidx])
    for ridx in range(rightIndex, len(right)):
        ret.append(right[ridx])

def mergeSort(arr):
    if len(arr)<=1:
        return arr
    mid = len(arr)//2
    left, right = arr[:mid], arr[mid:]
    sortedLeft, sortedRight = mergeSort(left), mergeSort(right)
    return merge(sortedLeft, sortedRight)


if __name__ == '__main__':
    ls = list(map(int, input().split()))
    mergeSort(ls)
    print(ls)