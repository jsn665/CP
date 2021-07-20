# 1759. Count Number of Homogenous Substrings
class Solution:
    def countHomogenous(self, s: str) -> int:
        start = 0
        res = 0
        for end in range(len(s)):
            if s[end] != s[start]:
                n = end - start
                res += (n * (n + 1)) // 2
                while start < end and s[end] != s[start]:
                    start += 1
            if end == len(s) - 1:
                n = (end - start) + 1
                res += (n * (n + 1)) // 2
        return res % 1000000007

