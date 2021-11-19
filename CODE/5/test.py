N = int(input())
A = []

for i in range(N):
    A.append(int(input().split()))

def findLongestDecend(lst):
    end = 0
    for i in range(1, len(lst)):
        if lst[i] < lst[end]:
            end+=1
        else:
            return end

for i in range(len(A)):
    end = findLongestDecend(A)
    for j in range(i+1, end):
        print()