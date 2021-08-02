class Solution:
    def checkIfCanBreak(self, s1: str, s2: str) -> bool:
        s1 = list(s1)
        s2 = list(s2)
        s1.sort()
        s2.sort()
        ok1 = True
        for i in range(len(s1)):
            if s1[i] < s2[i]:
                ok1 = False
                break
        ok2 = True
        for i in range(len(s1)):
            if s1[i] > s2[i]:
                ok2 = False
                break
        return True if ok1 or ok2 else False
