# 1791. Find Center of Star Graph
from typing import List
from collections import defaultdict
class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        graph = defaultdict(list)
        for edge in edges:
            graph[edge[0]].append(edge[1])
            graph[edge[1]].append(edge[0])

        res = 0
        most = 0
        for edge in graph:
            if len(graph[edge]) > most:
                res = edge
                most = len(graph[edge])
        return res