from typing import List
from bisect import bisect_left

# Meet in the middle technique
class Solution:
    def minAbsDifference(self, nums: List[int], goal: int) -> int:
        def subsequenceSums(resultSet: set, A: List[int], i: int, rs: int) -> None:
            if i >= len(A):
                resultSet.add(rs)
                return
            subsequenceSums(resultSet, A, i + 1, rs + A[i])
            subsequenceSums(resultSet, A, i + 1, rs)

        half = len(nums) // 2
        first = set()
        second = set()
        subsequenceSums(first, nums[:half], 0, 0)
        subsequenceSums(second, nums[half:], 0, 0)
        second = sorted(second)
        res = float('inf')
        for val in first:
            target = goal - val
            found = bisect_left(second, target)
            if found < len(second): 
                res = min(res, abs(target - second[found])) # Check the current index
            if found > 0:
                res = min(res, abs(target - second[found - 1])) # Check the previous index
        return res

