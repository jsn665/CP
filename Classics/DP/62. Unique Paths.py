# 62. Unique Paths
from functools import lru_cache
directions = [(-1, 0), (0, -1)]
class Solution:
    @lru_cache(None)
    def uniquePaths(self, m: int, n: int) -> int:
        if m < 0 or n < 0:
            return 0
        if m == 1 and n == 1:
            return 1
        res = 0
        for dx, dy in directions:
            res += self.uniquePaths(m + dx, n + dy)
        return res