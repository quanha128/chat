import random
binary = [''] * 10
for i in range(8):
    binary[0] += str(random.randint(0,1))
    binary[1] += str(random.randint(0,1))
    binary[2] += str(random.randint(0,1))
    binary[3] += str(random.randint(0,1))
a = random.sample(range(0,7), 2)
a.sort()
border1 = a[0]
border2 = a[1]
for i in range(4,10,2):
    print(i)
    for j in range(8):
        if j<= border1 or border2 < j:
            binary[i]   += binary[i-2][j]
            binary[i+1] += binary[i-1][j]
        else:
            binary[i]   += binary[i-1][j]
            binary[i+1] += binary[i-2][j]
for i in range(10):
    print(binary[i])
item = (("a", 30, 50), ("b", 20, 35), ("c", 40, 50),("d", 10,20),("e", 25, 30), ("f", 15, 25), ("g", 12, 20),("h", 10,15))
utility = 0
for i in range(10):
    tmp = 0
    for j in range(len(item)):
        if binary[i][j] == "1":
            tmp += item[j][2]
    print(tmp)
    utility = max(utility, tmp)
print(utility)