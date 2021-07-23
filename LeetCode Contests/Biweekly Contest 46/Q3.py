# 1765. Map of Highest Peak
from typing import List
from collections import deque
class Solution:
    def exploreNeighbors(self, isWater: List[List[int]], cr: int, cc: int, rQ: deque, cQ: deque,
                         visited: List[List[int]]):
        dir1 = [1, -1, 0, 0]
        dir2 = [0, 0, 1, -1]
        for i in range(4):
            nr = cr + dir1[i]  
            nc = cc + dir2[i]  
            if nr < 0 or nr >= len(isWater) or nc < 0 or nc >= len(isWater[0]):  
                continue
            if not visited[nr][nc]:  
                isWater[nr][nc] = isWater[cr][cc] + 1 
                visited[nr][nc] = 1
                rQ.append(nr)
                cQ.append(nc)
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        rQ = deque()
        cQ = deque()
        n = len(isWater)
        m = len(isWater[0])
        visited = [[0] * m for _ in range(n)]
        for row in range(n):
            for col in range(m):
                if isWater[row][col]:  
                    isWater[row][col] = 0
                    rQ.append(row)
                    cQ.append(col)
        while rQ:
            size = len(rQ)
            while size:
                row = rQ.popleft()
                col = cQ.popleft()
                self.exploreNeighbors(isWater, row, col, rQ, cQ, visited)
                size -= 1
        return isWater
