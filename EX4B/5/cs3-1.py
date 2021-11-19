import time

N = int(input("n: "))

cnt = 0
ptr = 0
prime = [None] * int(N/2 + 1)

prime[ptr] = 2
ptr += 1
prime[ptr] = 3
ptr+=1

start  = time.perf_counter()

for n in range(5, N, 2):
    i = 1
    while prime[i] * prime[i] <= n:
        cnt += 2
        if n%prime[i] ==0:
            break
        i += 1
    else:
        prime[ptr] = n
        ptr += 1
        cnt += 1

for i in range(ptr):
    print(prime[i])

end = time.perf_counter() - start

print("frequency:", cnt)
print("time taken:", round(end, 2))