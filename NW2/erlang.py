def fact(n):
    if n==0: return 1
    else: return n * fact(n-1)

def erlang(c, p):
    denum = 0
    for i in range(0, c+1):
        denum += p**i / fact(i)
    return (p**c/fact(c)) / denum

print(erlang(5, 4))

# p = lambda / u