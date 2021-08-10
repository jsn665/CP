# 377. Combination Sum IV
from typing import List
from functools import lru_cache
class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        @lru_cache(None)
        def dp(target: int):
            if target == 0:
                return 1
            res = 0
            for num in nums:
                if target - num >= 0:
                    res += dp(target - num)
            return res
        return dp(target)