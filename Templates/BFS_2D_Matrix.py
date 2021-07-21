from typing import List
from collections import deque

# BFS on 2D Matrix template
def exploreNeighbors(visited: List[List[int]], matrix: List[List[int]], cr: int, cc: int, rQ: deque, cQ: deque) -> None:
    dir1 = [1, -1, 0, 0]
    dir2 = [0, 0, 1, -1]
    for i in range(4):
        nr = cr + dir1[i]
        nc = cc + dir2[i]
        if nr < 0 or nr >= len(matrix) or nc < 0 or nc >= len(matrix[0]):
            continue
        if not visited[nr][nc]:
            rQ.append(nr)
            cQ.append(nc)
            visited[nr][nc] = 1
            pass  # fill in necessary code


def bfs(matrix: List[List[int]]):
    n = len(matrix)
    m = len(matrix[0])
    rQ = deque()
    cQ = deque()
    pass  # provide code for the first inputs of row queue (rQ) and column queue (cQ)
    visited = [[0] * m for _ in range(n)]
    while rQ:
        size = len(rQ)
        while size:
            row = rQ.popleft()
            col = cQ.popleft()
            exploreNeighbors(visited, matrix, row, col, rQ, cQ)
            size -= 1
    pass  # fill in necessary code
