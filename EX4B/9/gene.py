import random

W = 350
item = (("a", 30, 50), ("b", 20, 35), ("c", 40, 50),("d", 10,20),("e", 25, 30), ("f", 15, 25), ("g", 12, 20),("h", 10,15))

def generate():
    binary = ""
    for i in range(8):
        binary += str((random.randint(0,1)))
    return binary

def sum_price(binary):
    price = 0
    for i in range(len(item)):
        if binary[i] == "1":
            price += item[i][1]
    return price

def sum_utility(binary):
    utility = 0
    for i in range(len(item)):
        if binary[i] == "1":
            utility += item[i][2]
    return utility

def crossover(binary1, binary2):
  binary3 = ''
  binary4 = ''

  a = random.sample(range(0,7), 2)
  a.sort()

  border1 = (a[0])
  border2 = (a[1])

  for i in range(8):
    if i <= border1 or border2 < 1:
      binary3 += binary1[i]
      binary4 += binary2[2]
    else:
      binary3 += binary2[i]
      binary4 += binary1[i]
  
  return binary3, binary4

def move_to_nextgene(gene_set):
  gene_set[4][0],gene_set[5][0] = crossover(gene_set[4][0],gene_set[5][0])
  gene_set[6][0],gene_set[7][0] = crossover(gene_set[6][0],gene_set[7][0])
  gene_set[8][0],gene_set[9][0] = crossover(gene_set[8][0],gene_set[9][0])

  for i in range(4,10):
    gene_set[i][1] = sum_utility(gene_set[i][0])
  return gene_set

gene_set = []

while len(gene_set) < 10:
  gene = generate()

  if sum_price(gene) <=80:
    print(f'{gene}:価格{sum_price(gene)}:効用{sum_utility(gene)}') 
    gene_set.append([gene,sum_utility(gene)])


gene_set = sorted(gene_set, key=lambda x: x[1], reverse=True)
print(gene_set)

# 上位４つを次の世代に
for i in range(10):
  gene_set = move_to_nextgene(gene_set)
  gene_set = sorted(gene_set, key=lambda x: x[1], reverse=True)
  print(gene_set)
  print(gene_set[i][1])

# 下位６つを交配させて次の世代に