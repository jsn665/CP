# 1962. Remove Stones to Minimize the Total
from typing import List
from heapq import heappop, heappush
class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        heap = []
        for pile in piles:
            heappush(heap, -pile)
        while heap and k:
            val = -heappop(heap)
            val -= (val // 2)
            heappush(heap, -val)
            k -= 1
        res = 0
        while heap:
            res += (-heappop(heap))
        return res