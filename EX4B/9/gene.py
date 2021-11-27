import random

money = 80
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

gene_set = []

while len(gene_set) < 10:
    gene = generate()

    if sum_price(gene) <=80:
        print(f'{gene}:価格{sum_price(gene)}:効用{sum_utility(gene)}') 
        gene_set.append([gene,sum_utility(gene)])


gene_set = sorted(gene_set, key=lambda x: x[1], reverse=True)
print(gene_set)

# 上位４つを次の世代に

# 下位６つを交配させて次の世代に