# 1792. Maximum Average Pass Ratio
from typing import List
import heapq
class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        heap = []
        for c in classes:
            heapq.heappush(heap, (-(((c[0] + 1) / (c[1] + 1)) - c[0] / c[1]) , c[0], c[1]))
        while extraStudents:
            r, p, t = heapq.heappop(heap)
            p,t = p + 1, t + 1
            heapq.heappush(heap, (-(((p + 1) / (t + 1)) - p / t), p, t))
            extraStudents -= 1
        res = 0
        while heap:
            r, p , t = heapq.heappop(heap)
            res += (p / t)
        return res / len(classes)



