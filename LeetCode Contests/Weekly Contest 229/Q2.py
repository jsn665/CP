# 1770. Maximum Score from Performing Multiplication Operations
from typing import List
from functools import lru_cache
class Solution:
    def maximumScore(self, nums: List[int], multipliers: List[int]) -> int:
        @lru_cache(2000)
        def f(x: int, l: int, r: int):
            if x == len(multipliers):
                return 0
            return max((multipliers[x] * nums[l]) + f(x + 1, l + 1, r), (multipliers[x] * nums[r]) + f(x + 1, l, r - 1))

        return f(0, 0, len(nums) - 1)
