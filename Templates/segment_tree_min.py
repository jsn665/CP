class SegmentTree:
    def __init__(self, nums):
        self.n = len(nums)
        self.tree = [float('inf')] * (4 * self.n)
        self.lazy = [None] * (4 * self.n)
        self._build_tree(nums, 0, 0, self.n-1)
    
    def _build_tree(self, nums, idx, left, right):
        if left == right:
            self.tree[idx] = nums[left]
        else:
            mid = (left + right) // 2
            self._build_tree(nums, 2*idx+1, left, mid)
            self._build_tree(nums, 2*idx+2, mid+1, right)
            self.tree[idx] = min(self.tree[2*idx+1], self.tree[2*idx+2])
    
    def _update(self, idx, left, right, ul, ur, val):
        if self.lazy[idx]:
            self.tree[idx] = self.lazy[idx]
            if left != right:
                if not self.lazy[2*idx+1]:
                    self.lazy[2*idx+1] = self.lazy[idx]
                if not self.lazy[2*idx+2]:
                    self.lazy[2*idx+2] = self.lazy[idx]
            self.lazy[idx] = None
        
        if left > ur or right < ul:
            return
        
        if left >= ul and right <= ur:
            self.tree[idx] = val
            if left != right:
                if not self.lazy[2*idx+1]:
                    self.lazy[2*idx+1] = val
                if not self.lazy[2*idx+2]:
                    self.lazy[2*idx+2] = val
            return
        
        mid = (left + right) // 2
        self._update(2*idx+1, left, mid, ul, ur, val)
        self._update(2*idx+2, mid+1, right, ul, ur, val)
        self.tree[idx] = min(self.tree[2*idx+1], self.tree[2*idx+2])
    
    def update(self, left, right, val):
        self._update(0, 0, self.n-1, left, right, val)
    
    def _query(self, idx, left, right, ql, qr):
        if self.lazy[idx]:
            self.tree[idx] = self.lazy[idx]
            if left != right:
                if not self.lazy[2*idx+1]:
                    self.lazy[2*idx+1] = self.lazy[idx]
                if not self.lazy[2*idx+2]:
                    self.lazy[2*idx+2] = self.lazy[idx]
            self.lazy[idx] = None
        
        if left > qr or right < ql:
            return float('inf')
        
        if left >= ql and right <= qr:
            return self.tree[idx]
        
        mid = (left + right) // 2
        left_val = self._query(2*idx+1, left, mid, ql, qr)
        right_val = self._query(2*idx+2, mid+1, right, ql, qr)
        return min(left_val, right_val)
    
    def query(self, left, right):
        return self._query(0, 0, self.n-1, left, right)
