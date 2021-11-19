# from timeit import default_timer as timer
# from datetime import timedelta

def toString(List):
    return ''.join(List)

def permute(a, l, r, li):
    if l==r:
        li.append(toString(a))
    else:
        for i in range(l,r+1):
            a[l], a[i] = a[i], a[l]
            permute(a, l+1, r, li)
            a[l], a[i] = a[i], a[l]

li = []
string = input()
n = len(string)
a = list(string)
# start = timer()
permute(a, 0, n-1, li)
# end = timer()
# print("permute:", timedelta(seconds = end - start))

max = 0

# start = timer()
for word in li:
    for idx in range(1, len(word)):
        f_half = word[:idx]
        s_half = word[idx:]
        if f_half.startswith("0") or s_half.startswith("0"):
            continue
        mul = int(f_half) * int(s_half)
        if mul > max:
            max = mul
# end = timer()
# print("loop:", timedelta(seconds = end - start))

print(max)