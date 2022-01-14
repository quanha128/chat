import random
import time

start_time = time.perf_counter()

def generate_data (n):
    binary = ""
    for _ in range (n):
        binary += str (random.randint(0, 1))
    return binary

def eval (binary_value, w, v): 
    profit = 0
    total = 0
    for i in range(len(w)):
        if binary_value[i] == '1':
            profit += (v[i])
            total += (w[i])
    return profit, total

def choose_parent_locs (left, right):
    size = right - left
    a = random.sample (range(left,right), size)
    pairs = [[]for _ in range (int(size/2))]
    for ii in range (6):
        pairs[ii//2].append(a[ii])
    return pairs
    
def crossover (parent1, parent2, n): 
    a = random.sample(range (0,n), 2)
    a.sort()
    border1, border2 = a[0], a[1]
    child1 = ''
    child2 = ''
    for i in range (n):
        if i <= border1 or border2 < i:
            child1 += parent1[i]
            child2 += parent2[i]
        else:
            child1 += parent2[i]
            child2 += parent1[i]
    return child1, child2


def sort_generation (generation):
    return sorted(generation, key=lambda x: x[1], reverse=True)
    
if __name__ == '__main__':
    w_limit = 350
    w = [100,40,20,10,8,100,75,50,30,125,50,70,50,100,40,50,10,8,100,70,50,120]
    v = [50000,22000,8000,5500,6000,40000,30000,20000,15000,60000,32000,36400,28000,45000,24000,21000,5500,3000,40000,35000,24000,48000]
    n = len(w)
    generations = [[[] for _ in range (10)] for _ in range (10)]
    for i in range (10):
        data = generate_data(n)
        profit, total = eval(data, w, v)
        while total > w_limit:
            data = generate_data(n)
            profit, total = eval(data, w, v)
        generations [0][i] = [data, profit, total]
    generations[0] = sort_generation(generations[0])
    # print(generations)
    

    for i in range(1, 10):
        generations [i][:4] = generations [i-1][:4]
        print(generations [i][:4])
        pairs = choose_parent_locs(4, 10)
        # make children from the parent pairs
        for pair in pairs:
            # print(pairs)
            # print(pair)
            parent1, parent2 = generations[i-1][pair[0]][0] ,generations[i-1][pair[1]][0]
            child1, child2 = crossover (parent1, parent2, n)

            # print(parent1, parent2)
            # print()
            # print(child1, child2)

            p1, total1 = eval(child1, w, v)
            generations[i][pair[0]] = [child1, p1, total1]

            p2, total2 = eval(child2, w, v)
            generations[i][pair[1]] = [child2, p2, total2]
        generations[i] = sort_generation(generations[i])

    for i in range(10):
      print(generations[i][0][1], generations[i][0][2])
    
    # ans = 0

    # for i in range(10):
    #     print(generations[i])
    #     if generations[i][0][2] <= w_limit :
    #         ans = max(ans, generations[i][0][1])
    
    # print("Max profit: ", ans)

execution_time = time.perf_counter() - start_time
print("Running time: " ,execution_time)