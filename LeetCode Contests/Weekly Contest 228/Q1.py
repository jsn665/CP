# 1758. Minimum Changes To Make Alternating Binary String
import math
class Solution:
    def minOperations(self, s: str) -> int:
        str1 = [x for x in ['0', '1'] * math.ceil(len(s) / 2)]
        str2 = [x for x in ['1', '0'] * math.ceil(len(s) / 2)]
        change1 = 0
        change2 = 0
        for i in range(len(s)):
            if s[i] != str1[i]:
                change1 += 1
            if s[i] != str2[i]:
                change2 += 1
        return min(change1, change2)


