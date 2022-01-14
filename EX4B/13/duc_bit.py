import time
start_time = time.perf_counter()
def solution (w, v, w_limit):
    ret = -1
    n = len(w)
    for bit in range(1 << n):
        w_temp = 0
        v_temp = 0
        for index in range(n):
            if ((bit >> index) & 1):
                w_temp += w[index]
                v_temp += v[index]
        if w_temp <= w_limit:
            ret = max(ret, v_temp)
    return ret  
if __name__ == '__main__':
    w_limit = 350
    w = [100,40,20,10,8,100,75,50,30,125,50,70,50,100,40,50,10,8,100,70,50,120]
    v = [50000,22000,8000,5500,6000,40000,30000,20000,15000,60000,32000,36400,28000,45000,24000,21000,5500,3000,40000,35000,24000,48000]
    ans = solution(w,v,w_limit)
    print("Max profit: ", ans)
execution_time = time.perf_counter() - start_time
print("Running time: " ,execution_time)