# 1. Two Sum
from typing import List
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        targets = {}
        for index, num in enumerate(nums):
            need = target - num
            if need in targets:
                return [index, targets[need]]
            targets[num] = index
        raise Exception()