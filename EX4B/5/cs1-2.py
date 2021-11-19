import time

n = int(input("n: "))

cnt = 0
start  = time.perf_counter()
for i in range(2, n+1):
    for j in range (2, int(i/2)):
        cnt += 1
        if (i%j==0):
            isPrime = 0
            break
    else: print(i)

end = time.perf_counter() - start

print("frequency:", cnt)
print("time taken:", round(end, 2))