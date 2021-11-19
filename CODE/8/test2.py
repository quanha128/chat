def count_groups(friend_pairs):
    graph = {}
    visited = set()

    def dfs(visited, graph, node):
        if node not in visited:
            visited.add(node)
            for neighbour in graph[node]:
                dfs(visited, graph, neighbour)

    n = len(friend_pairs)
    for i in range(n):
        for j in range(2):
            
         