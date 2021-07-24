# Segment Tree for MAX Queries
class SegmentTreeTemplate:

    def __init__(self, arr: list):
        self.n = len(arr)
        self.ST = [0] * (self.n << 1)
        self.ST[self.n:] = arr[0:self.n]
        for i in range(self.n - 1, -1, -1):
            self.ST[i] = max(self.ST[i << 1], self.ST[(i << 1) + 1])

    def update(self, p: int, newVal: int) -> bool:
        p += self.n
        self.ST[p] = newVal
        while p > 1:
            p >>= 1
            newVal = max(self.ST[p << 1], self.ST[(p << 1) + 1])
            if newVal != self.ST[p]:
                self.ST[p] = newVal
            else:
                return True
        return True

    def getMax(self, l: int, r: int) -> int:
        l += self.n
        r += self.n
        maxx = float('-inf')
        while l < r:
            if (l & 1) == 1:
                maxx = max(maxx, self.ST[l])
                l += 1
            if (r & 1) == 1:
                r -= 1
                maxx = max(maxx, self.ST[r])
            r >>= 1
            l >>= 1
        return maxx