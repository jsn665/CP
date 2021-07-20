from typing import List

# Kadane's algorithm for finding the maximum subarray sum of an array of length > 0
def kadaneAlgo(nums: List) -> int:
    local_max = nums[0]
    global_max = nums[0]
    for i in range(1, len(nums)):
        num = nums[i]
        local_max = max(local_max + num, num)
        global_max = max(global_max, local_max)
    return global_max
