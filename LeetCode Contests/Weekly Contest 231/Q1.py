# 1784. Check if Binary String Has at Most One Segment of Ones
class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        started = 0
        for i in range(len(s)):
            if s[i] == '1':
                if started == -1:
                    return False
                started = 1
            else:
                started = -1
        return True

