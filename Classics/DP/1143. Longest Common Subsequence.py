# 1143. Longest Common Subsequence
from functools import lru_cache
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        @lru_cache(None)
        def dp(i: int, j: int):
            if i == len(text1) or j == len(text2):
                return 0
            res = 0
            if text1[i] == text2[j]:
                res = max(res, dp(i + 1, j + 1) + 1)
            else:
                res = max(res, dp(i + 1, j), dp(i, j + 1))
            return res
        return dp(0, 0)