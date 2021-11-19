log = {}

N = int(input())

for _ in range(N):
    A, B = input().split()
    log[int(A)] = int(B)

print(log)