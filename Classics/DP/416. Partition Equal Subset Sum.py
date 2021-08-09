# 416. Partition Equal Subset Sum
# Knapsack variant
from typing import List
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        S = sum(nums)
        return ((S & 1) == 0) and self.dfs(nums, 0, S // 2, {})

    def dfs(self, nums: List[int], index: int, S: int, dp: dict):
        if S == 0:
            return True
        elif index == len(nums) or S < 0:
            return False
        if (index, S) in dp:
            return dp[(index, S)]
        choose = self.dfs(nums, index + 1, S - nums[index], dp)
        ignore = self.dfs(nums, index + 1, S, dp)
        dp[(index, S)] = choose | ignore
        return dp[(index, S)]
