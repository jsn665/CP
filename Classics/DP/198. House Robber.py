# 198. House Robber
from typing import List
from functools import lru_cache
class Solution:
    def rob(self, nums: List[int]) -> int:
        @lru_cache(None)
        def dp(currentHouse: int):
            if currentHouse >= len(nums):
                return 0
            rob = dp(currentHouse + 2) + nums[currentHouse]
            ignore = dp(currentHouse + 1)
            return max(rob, ignore)
        return dp(0)