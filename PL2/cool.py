from queue import Queue
l = int(input("String Length:"))
s = ""
g = {}
goal = []
with open("input.txt") as f:
    lines = [x.strip() for x in f.readlines()]
    goal = lines[0].split(' ')
    for line in lines[1:]:
        r = line.split(' ')
        src = r[0]
        edge = r[1]
        dst = r[2]
        if src not in g.keys():
            g[src] = []
        g[src].append((dst, edge))
print(g)
src = input("Start from: ")
q = Queue()
q.put((src, ""))
res = {}
while not q.empty():
    u, crt_str = q.get()
    if len(crt_str) > l:
        break
    elif len(crt_str) == l:
        if u in goal:
            if crt_str not in res:
                print(crt_str)
                res[crt_str] = 1
        else:
            continue
    else:
        for dst, input in g[u]:
            q.put((dst, crt_str + input))