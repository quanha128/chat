import networkx as nx
import numpy as np
import queue

def my_extract_min2(D, X):
  arg_min = -1
  min_value = float('inf')
  for i in X:
    if D[i] < min_value:
        arg_min = i
        min_value = D[i]
  return arg_min


def my_Dijkstra(G, source):
  X = set(G.nodes)
  D = [float('inf')] * nx.number_of_nodes(G)
  D[source] = 0
  P = [-1] * nx.number_of_nodes(G)
  #iteration begin
  while X:
    u = my_extract_min2(D, X)
    X.remove(u)
    for v in G.neighbors(u):
      if v in X:
        new_distance = D[u] + G.edges[u, v]['weight']
        if D[v] > new_distance:
          D[v] = new_distance
          P[v] = u
  #iteration end
  return D, P


def restore_shortestpath(u, v, P):
  path = []
  temp = v
  while temp != u:
    parent = P[temp]
    path.append((parent, temp))
    temp = parent
  path.reverse()
  return path


def find_augmentpath(N, s, t):
  P = [-1] * nx.number_of_nodes(N)
  visited = set()
  stack = queue.LifoQueue()
  stack.put(s)
  while not stack.empty():
    v = stack.get()
    if v == t:
      return P, True
    if not v in visited:
      visited.add(v)
      for w in N.neighbors(v):
        if not w in visited and N.edges[v, w]['weight'] > 0:
          stack.put(w)
          P[w] = v
  return P, False


def min_capacity(N, path):
  min_cap = float('inf')
  for u, v in path:
    capacity = N.edges[u, v]['weight']
    if capacity < min_cap:
      min_cap = capacity
  return min_cap


def increase_flow(N, path, amount, flow):
  for u, v in path:
    if flow[(v, u)] <= 0:
      flow[(u, v)] += amount
    else:
      diff = flow[(v, u)] - amount
      if diff >= 0:
        flow[(v, u)] = diff
      else:
        flow[(u, v)] = -diff
        flow[(v, u)] = 0
    
    N.edges[u, v]['weight'] -= amount
    if N.has_edge(v, u):
      N.edges[v, u]['weight'] += amount
    else:
      N.add_edge(v, u, weight=amount)

def my_Ford_Fulkerson(G, s, t):
  N = G.copy()
  f = {}
  for u, v in N.edges:
    f[(u, v)] = 0
    f[(v, u)] = 0
  P, is_found = find_augmentpath(N, s, t)
  while is_found:
    augmentpath = restore_shortestpath(s, t, P)
    min_cap = min_capacity(N, augmentpath)
    increase_flow(N, augmentpath, min_cap, f)
    P, is_found = find_augmentpath(N, s, t)
  return N, f

def mincut_dfs(G, source):
  visited = set()
  stack = queue.LifoQueue()
  stack.put(source)
  while not stack.empty():
    v = stack.get()
    if not v in visited:
      visited.add(v)
    for w in G.neighbors(v):
        if not w in visited and G.edges[v, w]['weight'] > 0:
          stack.put(w)
  return visited, set(G.nodes)-visited

def matrix_value(M, c1, c2):
  if (c1, c2) in M.keys():
    return M[(c1, c2)]
  else:
    return M[(c2, c1)]

def my_Needleman_Wunsch(s1, s2, M, d):
  m = len(s1)
  n = len(s2)
  D = np.zeros((m+1, n+1))
  D[0, 0] = 0
  for i in range(1, m+1):
    D[i, 0] = -d*i
  for j in range(1, n+1):
    D[0, j] = -d*j
  for i in range(1, m+1):
    for j in range(1, n+1):
      mat_value = matrix_value(M, s1[i-1], s2[j-1])
      D[i, j] = max(D[i, j-1] - d, D[i-1, j] - d, D[i-1, j-1] + mat_value)
  return D[m, n]



class Cellular_Automaton:
  def __init__(self, cells, ruleset):
    self.cells = cells.copy()
    self.len = len(cells)
    self.ruleset = ruleset
  def __str__(self):
    result = ''
    for i in range(self.len):
      if self.cells[i] == 0:
        result += ' '
      else:
        result += '*'
    return result
  def transition(self):
    next_cells = [0] * self.len
    for i in range(self.len):
      if i == 0:
        neighbors = (self.cells[self.len - 1], self.cells[i], self.cells[i+1])
      elif i == self.len - 1:
        neighbors = (self.cells[i-1], self.cells[i], self.cells[0])
      else:
        neighbors = (self.cells[i-1], self.cells[i], self.cells[i+1])
      next_cells[i] = self.ruleset[neighbors]
    self.cells = next_cells

