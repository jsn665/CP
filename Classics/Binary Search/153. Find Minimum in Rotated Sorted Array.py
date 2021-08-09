# 153. Find Minimum in Rotated Sorted Array
from typing import List
class Solution:
    def findMin(self, nums: List[int]) -> int:
        n = len(nums)
        low = 0
        high = n - 1
        while low <= high:
            mid = low + (high - low) // 2
            prev = nums[mid - 1] if mid - 1 >= 0 else float('inf')
            curr = nums[mid]
            nextt = nums[mid + 1] if mid + 1 < n else float('inf')
            if curr < prev and curr < nextt:
                return curr
            elif curr >= nums[0]:
                low = mid + 1
            else:
                high = mid - 1
        return nums[0]