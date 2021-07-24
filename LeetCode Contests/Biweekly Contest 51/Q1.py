# 1844. Replace All Digits with Characters
class Solution:
    def replaceDigits(self, s: str) -> str:
        def shift(a, num):
            return ord(a) + (ord(num) - ord('0'))
        s = list(s)
        for i in range(1, len(s)):
            if i % 2 > 0:
                s[i] = chr(shift(s[i - 1], s[i]))
        return ''.join(s)