import networkx as nx
import matplotlib.pyplot as plt
import queue

# # load the data of a graph
# G=nx.read_edgelist('test.edgelist', nodetype=int)

# # display the graph
# nx.draw_networkx(G)
# plt.show()

def dfs(g, v):
    S = set()
    def visit(g, v):
        S.add(v)
        for n in g.neighbors(v):
                if n not in S:
                    # visit n
                    print(n)
                    S.add(n)
                    # do dfs with n as vertex
                    visit(g, n)
