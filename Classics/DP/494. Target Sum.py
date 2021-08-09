# 494. Target Sum
# Knapsack 0/1 variant
from typing import List
class Solution:
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        dp = {}
        return self.dfs(nums, S, 0, dp)

    def dfs(self, nums:List[int], S:int, index: int, dp: dict):
        if index == len(nums) and S == 0:
            return 1
        elif index == len(nums):
            return 0
        if (index, S) in dp:
            return dp[(index, S)]
        choose = self.dfs(nums, S + nums[index], index + 1, dp)
        ignore = self.dfs(nums, S - nums[index], index + 1, dp)
        dp[(index, S)] = choose + ignore
        return dp[(index, S)]
