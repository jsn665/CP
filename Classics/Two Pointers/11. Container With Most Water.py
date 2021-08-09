# 11. Container With Most Water
from typing import List
class Solution:
    def maxArea(self, heights: List[int]) -> int:
        low = 0
        high = len(heights) - 1
        res = 0
        while low < high:
            height = min(heights[low], heights[high])
            length = high - low
            res = max(res, height * length)
            if heights[low] <= heights[high]:
                low += 1
            else:
                high -= 1
        return res