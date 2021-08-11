# 207. Course Schedule
from typing import List
from collections import defaultdict, deque
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = defaultdict(list)
        in_degree = defaultdict(int)
        edges = 0
        for course, prereq in prerequisites:
            graph[prereq].append(course)
            in_degree[course] += 1
            edges += 1
        dq = deque()
        for node in graph:
            if in_degree[node] == 0:
                dq.append(node)
        while dq:
            currentNode = dq.popleft()
            for edge in graph[currentNode]:
                in_degree[edge] -= 1
                edges -= 1
                if in_degree[edge] == 0:
                    dq.append(edge)
        return edges == 0