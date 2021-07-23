# 1764. Form Array by Concatenating Subarrays of Another Array
from typing import List
class Solution:
    def canChoose(self, groups: List[List[int]], nums: List[int]) -> bool:
        i = 0
        valid = 0
        for g in groups:
            for j in range(i, len(nums)):
                if nums[j: j + len(g)] == g:
                    valid += 1
                    i = j + len(g)
                    break
        return valid == len(groups)






