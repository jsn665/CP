from typing import List
class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        larg = max(candies)
        res = [False] * len(candies)
        for i in range(len(candies)):
            res[i] = True if candies[i] + extraCandies >= larg else False
        return res