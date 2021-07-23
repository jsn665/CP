# 1790. Check if One String Swap Can Make Strings Equal
class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        if s1 == s2:
            return True
        p = 0
        a = float('inf')
        b = 0
        s1 = list(s1)
        s2 = list(s2)
        for i in range(len(s1)):
            if s1[i] != s2[i]:
                p += 1
                a = min(a, i)
                b = max(b, i)
        s1[a], s1[b] = s1[b], s1[a]
        if s1 == s2:
            return True
        else:
            s1[a], s1[b] = s1[b], s1[a]
            s2[a], s2[b] = s2[b], s2[a]
            if s1 == s2:
                return True
            else:
                return False

