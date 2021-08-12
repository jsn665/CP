# 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
from typing import List
class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        shortest_paths = [[float('inf')] * n for _ in range(n)]
        for source in range(n):
            shortest_paths[source][source] = 0
        for source, target, weight in edges:
            shortest_paths[source][target] = weight
            shortest_paths[target][source] = weight
        for intermediate in range(n):
            for source in range(n):
                for target in range(n):
                    if shortest_paths[source][target] > shortest_paths[source][intermediate] + shortest_paths[intermediate][target]:
                        shortest_paths[source][target] = shortest_paths[source][intermediate] + shortest_paths[intermediate][target]
        result = -1
        minimum_city_count = float('inf')
        for source in range(n):
            city_count = 0
            for target in range(n):
                if shortest_paths[source][target] <= distanceThreshold:
                    city_count += 1
            if minimum_city_count >= city_count and source > result:
                result = source
                minimum_city_count = city_count
        return result