# 1846. Maximum Element After Decreasing and Rearranging
from typing import List
class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
        arr.sort()
        if arr[0] != 1:
            arr[0] = 1
        res = arr[0]
        for i in range(1, len(arr)):
            if abs(arr[i] - arr[i - 1]) > 1:
               arr[i] = arr[i - 1] + 1
            res = max(res, arr[i])
        return res