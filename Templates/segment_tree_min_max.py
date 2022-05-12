# Segment Tree for Min,Max Queries ONLY
class SegmentTree:

    def __init__(self, arr: list, f: 'Optional'):
        self.n = len(arr)
        self.f = f
        self.ST = [0] * (self.n << 1)
        self.ST[self.n:] = arr[0:self.n]
        for i in range(self.n - 1, -1, -1):
            self.ST[i] = self.f(self.ST[i << 1], self.ST[(i << 1) + 1])

    def update(self, p: int, newVal: int) -> None:
        p += self.n
        self.ST[p] = newVal
        while p > 1:
            p >>= 1
            newVal = self.f(self.ST[p << 1], self.ST[(p << 1) + 1])
            if newVal != self.ST[p]:
                self.ST[p] = newVal
            else:
                return

    # query from [l,r) **r is non inclusive**
    def query(self, l: int, r: int) -> int:
        l += self.n
        r += self.n
        res = float('-inf') if self.f == max else float('inf')
        while l < r:
            if (l & 1) == 1:
                res = self.f(res, self.ST[l])
                l += 1
            if (r & 1) == 1:
                r -= 1
                res = self.f(res, self.ST[r])
            r >>= 1
            l >>= 1
        return res
