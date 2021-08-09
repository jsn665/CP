# 1964. Find the Longest Valid Obstacle Course at Each Position
from typing import List
from bisect import bisect_right
class Solution:
    def longestObstacleCourseAtEachPosition(self, nums: List[int]) -> List[int]:
        res = []
        piles = [nums[0]]
        res.append(1)
        for i in range(1, len(nums)):
            top_of_pile = bisect_right(piles, nums[i])
            if top_of_pile == len(piles):
                piles.append(0)
            piles[top_of_pile] = nums[i]
            res.append(top_of_pile + 1)
        return res