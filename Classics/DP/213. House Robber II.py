# 213. House Robber II
from typing import List
from functools import lru_cache

class Solution:
    def rob(self, nums: List[int]) -> int:
        @lru_cache(None)
        def dp(currentHouse: int, robbedFirst: bool):
            if currentHouse >= len(nums):
                return 0
            elif currentHouse == len(nums) - 1 and robbedFirst:
                return 0
            elif currentHouse == len(nums) - 1 and not robbedFirst:
                return nums[currentHouse]
            rob = dp(currentHouse + 2, robbedFirst) + nums[currentHouse]
            ignore = dp(currentHouse + 1, robbedFirst)
            return max(rob, ignore)

        if len(nums) == 1:
            return nums[0]
        return max(dp(0, True), dp(1, False))
