# 1760. Minimum Limit of Balls in a Bag
from typing import List
class Solution:
    def condition(self, A: List[int], mid: int, maxOperation: int) -> bool:
        count = 0
        for val in A:
            count += (val - 1) // mid
            if count > maxOperation:
                return False
        return True
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        low = 1
        high = 10000000009
        while low < high:
            mid = low + high >> 1
            if self.condition(nums, mid, maxOperations):
                high = mid
            else:
                low = mid + 1
        return low

