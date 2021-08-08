# Patience Sort LIS (N log N)
from bisect import bisect_left
from typing import List
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        piles = [nums[0]]
        for i in range(1, len(nums)):
            top_of_pile = bisect_left(piles, nums[i])
            if top_of_pile == len(piles):
                piles.append(0)
            piles[top_of_pile] = nums[i]
        return len(piles)