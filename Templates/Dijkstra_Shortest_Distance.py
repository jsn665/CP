# Lazy Dijkstra's shortest distance **Node id's are 1-indexed
# param(graph) -> adjacency list
# param(start) -> starting node
# param(n) -> number of nodes
import heapq


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
