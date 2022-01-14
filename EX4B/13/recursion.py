import time

def solution(i, j, w, v):
  ret = -1
  n = len(w)
  if i == n:
    return 0
  elif j < w[i]:
    return solution(i+1, j, w, v)
  elif j-w[i] >= 0 and i<n:
    return max(solution(i+1,j-w[i],w,v)+v[i], solution(i+1,j,w,v))
  return ret

if __name__ == '__main__':
  w_limit = 350
  w = [100,40,20,10,8,100,75,50,30,125,50,70,50,100,40,50,10,8,100,70,50,120]
  v = [50000,22000,8000,5500,6000,40000,30000,20000,15000,60000,32000,36400,28000,45000,24000,21000,5500,3000,40000,35000,24000,48000]
  start_time = time.perf_counter()
  ans = solution(0, w_limit, w, v)
  execution_time = time.perf_counter() - start_time
  print("Max:", ans)
  print("Time:", execution_time)