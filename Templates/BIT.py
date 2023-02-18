class BIT:
    def __init__(self, nums):
        self.nums = nums
        self.tree = [0] * (len(nums) + 1)
        for i in range(len(nums)):
            self._update(i, nums[i])
    
    def _update(self, i, val):
        i += 1
        while i < len(self.tree):
            self.tree[i] += val
            i += i & (-i)
    
    def update(self, i, val):
        diff = val - self.nums[i]
        self.nums[i] = val
        self._update(i, diff)
    
    def _prefix_sum(self, i):
        i += 1
        res = 0
        while i > 0:
            res += self.tree[i]
            i -= i & (-i)
        return res
    
    def get_sum(self, i, j):
        return self._prefix_sum(j) - self._prefix_sum(i-1)


    def __str__(self):
        return str(self.tree)
