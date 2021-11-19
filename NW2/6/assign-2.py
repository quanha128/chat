# To add a new cell, type '# %%'
# To add a new markdown cell, type '# %% [markdown]'
# %%
import networkx as nx
import heapq
import matplotlib.pyplot as plt


# %%
G=nx.read_weighted_edgelist('bf.edgelist', create_using=nx.DiGraph(), nodetype=int)
path1_4 = nx.all_simple_edge_paths(G, source=1, target=4)
path2_4 = nx.all_simple_edge_paths(G, source=2, target=4)
path1_3 = nx.all_simple_edge_paths(G, source=1, target=3)
rt1 = []
rt2 = []
rt3 = []
for i in path1_4:
    rt1.append(list(i))
for i in path2_4:
    rt2.append(list(i))
for i in path1_3:
    rt3.append(list(i))
print(rt1)
print(rt2)
print(rt3)


# %%
res = { i : 0 for i in G.edges() }


# %%
flag = True
for e1 in rt1:
    for e2 in rt2:
        for e3 in rt3:
            for i in e1:
                res[i]+=2
            for j in e2:
                res[j]+=3
            for k in e3:
                res[k]+=4
            for e in res:
                if res[e] > G.edges[e]['weight']:
                    flag &= False
            print(res, flag)
            for i in res:
                res[i] = 0
            flag = True


# %%



