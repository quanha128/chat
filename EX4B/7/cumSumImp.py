def cummulativeSum(ls: list):
    cs = []
    s = 0
    cs.append(s) #cs[0] = 0
    for element in ls:
        s += element
        cs.append(s)
    return cs

def solution(k:int, ls: list):
    cs = cummulativeSum(ls)
    ans = -1
    for i in range(len(ls)):
        if i+k >= len(cs):
            break
        temp = cs[i+k] - cs[i]
        ans = max(temp, ans)
    return ans

if __name__ == '__main__':
    k = int(input())
    ls = list(map(int, input().split()))
    ans = solution(k, ls)
    print(ans)