def solution(k:int, ls:list):
    ret = -1
    N = len(ls)
    for i in range(N):
        if i+k-1 > N-1:
            break
        temp = 0
        for j in range(k):
            temp += ls[i+j]
        ret = max(ret, temp)
    return ret

if __name__ == '__main__':
    k = int(input())
    ls = list(map(int, input().split()))
    ans = solution(k, ls)
    print(ans)