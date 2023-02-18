class SegmentTree:
    def __init__(self, nums):
        self.n = len(nums)
        self.tree = [0] * (4 * self.n)
        self.lazy = [0] * (4 * self.n)
        self._build_tree(nums, 0, 0, self.n-1)
    
    def _build_tree(self, nums, idx, left, right):
        if left == right:
            self.tree[idx] = nums[left]
        else:
            mid = (left + right) // 2
            self._build_tree(nums, 2*idx+1, left, mid)
            self._build_tree(nums, 2*idx+2, mid+1, right)
            self.tree[idx] = self.tree[2*idx+1] + self.tree[2*idx+2]
    
    def _update(self, idx, left, right, ul, ur, val):
        if self.lazy[idx] != 0:
            self.tree[idx] += (right - left + 1) * self.lazy[idx]
            if left != right:
                self.lazy[2*idx+1] += self.lazy[idx]
                self.lazy[2*idx+2] += self.lazy[idx]
            self.lazy[idx] = 0
        
        if left > ur or right < ul:
            return
        
        if left >= ul and right <= ur:
            self.tree[idx] += (right - left + 1) * val
            if left != right:
                self.lazy[2*idx+1] += val
                self.lazy[2*idx+2] += val
            return
        
        mid = (left + right) // 2
        self._update(2*idx+1, left, mid, ul, ur, val)
        self._update(2*idx+2, mid+1, right, ul, ur, val)
        self.tree[idx] = self.tree[2*idx+1] + self.tree[2*idx+2]
    
    def update(self, left, right, val):
        self._update(0, 0, self.n-1, left, right, val)
    
    def _query(self, idx, left, right, ql, qr):
        if self.lazy[idx] != 0:
            self.tree[idx] += (right - left + 1) * self.lazy[idx]
            if left != right:
                self.lazy[2*idx+1] += self.lazy[idx]
                self.lazy[2*idx+2] += self.lazy[idx]
            self.lazy[idx] = 0
        
        if left > qr or right < ql:
            return 0
        
        if left >= ql and right <= qr:
            return self.tree[idx]
        
        mid = (left + right) // 2
        left_sum = self._query(2*idx+1, left, mid, ql, qr)
        right_sum = self._query(2*idx+2, mid+1, right, ql, qr)
        return left_sum + right_sum
    
    def query(self, left, right):
        return self._query(0, 0, self.n-1, left, right)

    def __str__(self):
        return str(self.tree)
