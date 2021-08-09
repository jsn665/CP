# 1961. Check If String Is a Prefix of Array
from typing import List
class Solution:
    def isPrefixString(self, s: str, words: List[str]) -> bool:
        t = []
        for word in words:
            t.append(word)
            if ''.join(t) == s:
                return True
        return False