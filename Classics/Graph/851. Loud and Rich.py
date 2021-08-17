# 851. Loud and Rich
from typing import List
from collections import defaultdict


class Solution:
    def loudAndRich(self, richer: List[List[int]], quiet: List[int]) -> List[int]:
        def dfs(currentVertex: int):
            nonlocal graph, dp
            if currentVertex in dp:
                return dp[currentVertex]
            quietest = currentVertex
            for neighbor in graph[currentVertex]:
                quietest = min(quietest, dfs(neighbor), key=lambda x: quiet[x])
            dp[currentVertex] = quietest
            return dp[currentVertex]

        n = len(quiet)
        graph = defaultdict(list)
        for target, source in richer:
            graph[source].append(target)
        res = [0] * n
        dp = {}
        for vertex in range(n):
            res[vertex] = dfs(vertex)
        return res