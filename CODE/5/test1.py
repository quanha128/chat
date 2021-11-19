T = int(input())

for _ in range(T):
    R,G,B = input().split()
    R=int(R)
    G=int(G)
    B=int(B)

    if R == G or R == B:
        print(R)
        continue
    elif G == B:
        print(B)
        continue

    diff_RG = abs(R-G)
    diff_RB = abs(R-B)
    diff_GB = abs(B-G)

    if diff_GB%3!=0 and diff_RG%3!=0 and diff_RB%3!=0:
        print(-1)
        continue

    res = 10000000000000000

    if diff_RG%3==0:
        RG = 0
        n = diff_RG/3
        RG+=(2*n+ min(R,G) + n)
        if RG<res: res = RG
    if diff_RB%3==0:
        RB=0
        n = diff_RB/3
        RB+=(2*n + min(R,B) + n)
        if RB<res: res = RB
    if diff_GB%3==0:
        GB=0
        n = diff_GB/3
        GB+=(2*n+ min(G,B) + n)
        if GB<res: res = GB

    print(int(res))