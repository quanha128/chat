def factorial(n):
    mul=1
    for i in range(1,n+1):
        mul*=i
    return mul

for i in range(1,51):
    print(i,"! =",factorial(i))


