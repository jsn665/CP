# 152. Maximum Product Subarray
from typing import List
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        minn = maxx = 1
        res = float('-inf')
        for num in nums:
            temp = minn * num
            minn = min(minn * num, num, maxx * num)
            maxx = max(maxx * num, num, temp)
            res = max(maxx, res)
        return res