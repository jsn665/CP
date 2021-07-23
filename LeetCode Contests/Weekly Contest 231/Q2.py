# 1785. Minimum Elements to Add to Form a Given Sum
from typing import List
class Solution:
    def minElements(self, nums: List[int], limit: int, goal: int) -> int:
        s = sum(nums)
        t = abs(goal - s)
        return (t // limit) + ( 1 if t % limit > 0 else 0)

