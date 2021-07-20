class Solution:
    def maximumScore(self, a: int, b: int, c: int) -> int:
        if c < a and b < a:
            return self.maximumScore(c, b, a)
        elif a < b and c < b:
            return self.maximumScore(c, a, b)
        if a + b <= c:
            return a + b
        else:
            return c + (((a + b) - c) // 2)

