# 1786. Number of Restricted Paths From First to Last Node
from typing import List
import heapq
from collections import defaultdict


def dijkstra(graph, start, n):
    distance = [float('inf')] * (n + 1)
    distance[start] = 0
    visited = [0] * (n + 1)
    heap = [(0, start)]
    while heap:
        min_dist, node_id = heapq.heappop(heap)
        visited[node_id] = 1
        if distance[node_id] < min_dist: continue
        for edge in graph[node_id]:
            if visited[edge[1]]: continue
            new_dist = distance[node_id] + edge[0]
            if new_dist < distance[edge[1]]:
                distance[edge[1]] = new_dist
                heapq.heappush(heap, (new_dist, edge[1]))
    return distance


class Solution:
    def countRestrictedPaths(self, n: int, edges: List[List[int]]) -> int:
        graph = defaultdict(list)
        for edges in edges:
            graph[edges[0]].append([edges[2], edges[1]])
            graph[edges[1]].append([edges[2], edges[0]])
        dist = dijkstra(graph, n, n)
        
        @lru_cache(None)
        def dfs(curr):
            if curr == n:
                return 1
            res = 0
            for edge in graph[curr]:
                if dist[edge[1]] < dist[curr]:
                    res += dfs(edge[1])
            return res % 1000000007

        return dfs(1)