# 15. 3Sum
from typing import List
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        nums.sort()
        res = []
        for i in range(n):
            if i != 0 and nums[i] == nums[i - 1]:
                continue
            self.twoSumII(nums, i, res)
        return res

    def twoSumII(self, nums: List[int], chosen: int, res: List[List[int]]) -> None:
        low = chosen + 1
        high = len(nums) - 1
        while low < high:
            have = nums[chosen] + nums[low] + nums[high]
            if have < 0:
                low += 1
            elif have > 0:
                high -= 1
            else:
                res.append([nums[chosen], nums[low], nums[high]])
                low += 1
                high -= 1
                while low < high and nums[low] == nums[low - 1]:
                    low += 1