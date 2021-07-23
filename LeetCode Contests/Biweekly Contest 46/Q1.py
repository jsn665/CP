# 1763. Longest Nice Substring
class Solution:
    def longestNiceSubstring(self, s: str) -> str:
        def isNice(substr: str) -> bool:
            cnt = set()
            for c in substr:
                cnt.add(c)

            for c in substr:
                if c.swapcase() not in cnt:
                    return False
            return True

        maxLen = 0
        res = ""
        for i in range(len(s)):
            for j in range(len(s), i, -1):
                if isNice(s[i:j]):
                    if j - i > maxLen:
                        maxLen = j - i
                        res = s[i:j]
        return res



