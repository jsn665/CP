# 1780. Check if Number is a Sum of Powers of Three
class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        while n > 1:
            if n % 3 == 0:
                return False
            n /= 3
        return True



