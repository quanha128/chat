def ssort(lst):
    for i in range(len(lst)-1):
        min = lst[i]
        minpos=i
        for j in range(i+1, len(lst)):
            if lst[j] < min:
                min = lst[j]
                minpos = j
        if i != minpos:
            tmp = lst[i]
            lst[i] = min
            lst[minpos] = tmp
    return lst

def qsort(lst):
    if len(lst) <= 1:
        return lst
    pivot = lst[0]
    lst1 = [item for item in lst if item < pivot]
    lst2 = [item for item in lst if item > pivot]
    return qsort(lst1) + [pivot] + qsort(lst2)

import matplotlib.pyplot as plt
import timeit
import random

def setup_lst(x):
    lst=sorted(random.sample(range(x*2), k=x))
    return lst

xs = range(20,500,20)
ys=[]

for x in xs:
    time = timeit.repeat('ssort(lst)', setup='lst=setup_lst(x)', globals=globals(), repeat=1000, number=1)
    ys.append(sum(time)/(r*n))
    
plt.plot(xs,ys,'o')
plt.ylim(0, max(ys)*1.1)
plt.xlabel('Length of list', fontsize=9)
plt.ylabel('Average time', fontsize=9)
plt.show()

n=1
r=1000

xs = range(20,500,20)
ys=[]

for x in xs:
    time = timeit.repeat('qsort(lst)', setup='lst=setup_lst(x)', globals=globals(), repeat=r, number=n)
    ys.append(sum(time)/(r*n))

plt.plot(xs,ys,'o')
plt.ylim(0, max(ys)*1.1)
plt.xlabel('Length of list', fontsize=9)
plt.ylabel('Average time', fontsize=9)
plt.show()