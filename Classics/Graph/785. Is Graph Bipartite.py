# 785. Is Graph Bipartite?
from typing import List
class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        def dfs(currentVertex: int, color: int):
            nonlocal nodeColors
            nodeColors[currentVertex] = color
            for neighbor in graph[currentVertex]:
                if nodeColors[neighbor] == -1 and not dfs(neighbor, color ^ 1):
                    return False
                if nodeColors[neighbor] == nodeColors[currentVertex]:
                    return False
            return True
        n = len(graph)
        nodeColors = [-1] * n
        for vertex in range(n):
            if nodeColors[vertex] == -1 and not dfs(vertex, 0):
                return False
        return True