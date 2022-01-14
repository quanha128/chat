import random
import time

def generate(n):
  binary = ""
  for i in range(n):
    binary += str((random.randint(0,1)))
  return binary

def sum_weight(binary, w):
  weight = 0
  for i in range(len(w)):
    if binary[i] == "1":
      weight += w[i]
  return weight

def sum_utility(binary, v):
  utility = 0
  for i in range(len(v)):
    if binary[i] == "1":
      utility += v[i]
  return utility

def crossover(binary1, binary2, n):
  binary3 = ''
  binary4 = ''

  a = random.sample(range(0,n), 2)
  a.sort()

  border1 = (a[0])
  border2 = (a[1])

  for i in range(n):
    if i <= border1 or border2 < 1:
      binary3 += binary1[i]
      binary4 += binary2[2]
    else:
      binary3 += binary2[i]
      binary4 += binary1[i]
  
  return binary3, binary4

def move_to_nextgene(gene_set, n):
  # p = shuffled list from range(4,10)
  p = random.sample(range(4,10), 6)
  
  # crossover randomly between parents' last 6 genes
  gene_set[p[0]][0],gene_set[p[1]][0] = crossover(gene_set[p[0]][0],gene_set[p[1]][0], n)
  gene_set[p[2]][0],gene_set[p[3]][0] = crossover(gene_set[p[2]][0],gene_set[p[3]][0], n)
  gene_set[p[4]][0],gene_set[p[5]][0] = crossover(gene_set[p[4]][0],gene_set[p[5]][0], n)

  # recalculate profit and weight of newly created children
  for i in range(4,10):
    gene_set[i][1] = sum_utility(gene_set[i][0], v)
    gene_set[i][2] = sum_weight(gene_set[i][0], w)
  
  return gene_set

if __name__ == '__main__':
  w_limit = 350
  w = [100,40,20,10,8,100,75,50,30,125,50,70,50,100,40,50,10,8,100,70,50,120]
  v = [50000,22000,8000,5500,6000,40000,30000,20000,15000,60000,32000,36400,28000,45000,24000,21000,5500,3000,40000,35000,24000,48000]
  n = len(w)
  gene_set = []

  start_time = time.perf_counter()
  # generate first generation
  while len(gene_set) < 10:
    gene = generate(n)
    if sum_weight(gene,w) <= w_limit:
      # print(f'{gene}:weight{sum_weight(gene, w)}:profit:{sum_utility(gene, v)}')
      gene_set.append([gene,sum_utility(gene, v),sum_weight(gene, w)])
  
  ans = 0
  # crossover 10 generations
  for _ in range(10):
    gene_set = sorted(gene_set, key=lambda x: x[1], reverse=True)
    
    for gene in gene_set:
      # if gene's weight <= 350 
      if (gene[2] <= w_limit):
        # if gene's profit > current max
        if (ans < gene[1]): ans = gene[1]
    # move to next generation
    gene_set = move_to_nextgene(gene_set, n)
  
  execution_time = time.perf_counter() - start_time
  print("Max:", ans)
  print("Time:", execution_time)