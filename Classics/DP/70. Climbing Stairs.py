# 70. Climbing Stairs
from functools import lru_cache
class Solution:
    @lru_cache(None)
    def climbStairs(self, n: int) -> int:
        if n == 0:
            return 1
        elif n < 0:
            return 0
        one_step = self.climbStairs(n - 1)
        two_step = self.climbStairs(n - 2)
        return one_step + two_step