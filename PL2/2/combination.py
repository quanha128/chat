def combination(xs,n):
    if n<=0:
        return [[]]
    l = []
    for i in range(0, len(xs)):
        m = xs[i]           # hd
        new_xs = xs[i+1:]   # tl
        for p in combination(new_xs, n-1):
            l.append([m]+p)
    return l

print(combination([1,2,3], 2))