# 1768. Merge Strings Alternately
class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        i = 0
        j = 0
        n = len(word1)
        m = len(word2)
        turn = 0
        res = ""
        while i < n and j < m:
            if not turn:
               res += word1[i]
               i += 1
               turn = 1
            else:
                res += word2[j]
                j += 1
                turn = 0
        while i < n:
            res += word1[i]
            i += 1
        while j < m:
            res += word2[j]
            j += 1
        return res

