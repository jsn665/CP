# 139. Word Break
from typing import List
from functools import lru_cache
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        @lru_cache(None)
        def dp(i: int) -> bool:
            if i == len(s):
                return True
            res = False
            for word in wordDict:
                if s[i : i + len(word)] == word:
                    res = dp(i + len(word))
                    if res:
                        return True
            return res
        return dp(0)