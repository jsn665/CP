# 323. Number of Connected Components in an Undirected Graph
from typing import List
from collections import defaultdict
class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        def dfs(visited: set, graph: defaultdict, currentVertex):
            visited.add(currentVertex)
            for neighbor in graph[currentVertex]:
                if neighbor not in visited:
                    dfs(visited, graph, neighbor)
        graph = defaultdict(list)
        for source, target in edges:
            graph[source].append(target)
            graph[target].append(source)
        visited = set()
        res = 0
        for vertex in range(n):
            if vertex not in visited:
                dfs(visited, graph, vertex)
                res += 1
        return res