# 1779. Find Nearest Point That Has the Same X or Y Coordinate
from typing import List
import heapq
class Solution:
    def nearestValidPoint(self, x: int, y: int, points: List[List[int]]) -> int:
        valid = []
        for i, point in enumerate(points):
            xp = point[0]
            yp = point[1]
            if xp == x or yp == y:
                dist = abs(x - xp) + abs(y - yp)
                heapq.heappush(valid, (dist, i, point))
        return heapq.nsmallest(1, valid)[0][1] if valid else -1






