# 213. House Robber II
from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        def helper(currentHouse: int, nums: List[int], dp: dict):
            if currentHouse >= len(nums):
                return 0
            if currentHouse in dp:
                return dp[currentHouse]
            rob = helper(currentHouse + 2, nums, dp) + nums[currentHouse]
            ignore = helper(currentHouse + 1, nums, dp)
            dp[currentHouse] = max(rob, ignore)
            return dp[currentHouse]
        return max(helper(0, nums[:-1], {}), helper(0, nums[1:], {}))
