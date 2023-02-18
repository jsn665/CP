class SegmentTree:
    def __init__(self, arr):
        self.arr = arr
        self.n = len(arr)
        self.tree = [0] * (4 * self.n)
        self.lazy = [0] * (4 * self.n)
        self.build_tree(1, 0, self.n-1)
    
    def build_tree(self, node, start, end):
        if start == end:
            self.tree[node] = self.arr[start]
        else:
            mid = (start + end) // 2
            left_child = 2 * node
            right_child = 2 * node + 1
            self.build_tree(left_child, start, mid)
            self.build_tree(right_child, mid+1, end)
            self.tree[node] = self.tree[left_child] ^ self.tree[right_child]
    
    def query(self, left, right):
        return self._query(1, 0, self.n-1, left, right)
    
    def _query(self, node, start, end, left, right):
        if left > end or right < start:
            return 0
        self._propagate(node, start, end)
        if left <= start and right >= end:
            return self.tree[node]
        mid = (start + end) // 2
        left_xor = self._query(2 * node, start, mid, left, right)
        right_xor = self._query(2 * node + 1, mid+1, end, left, right)
        return left_xor ^ right_xor
    
    def update(self, left, right, val):
        self._update(1, 0, self.n-1, left, right, val)
    
    def _update(self, node, start, end, left, right, val):
        if left > end or right < start:
            return
        self._propagate(node, start, end)
        if left <= start and right >= end:
            self.tree[node] ^= val
            self.lazy[node] ^= val
            return
        mid = (start + end) // 2
        self._update(2 * node, start, mid, left, right, val)
        self._update(2 * node + 1, mid+1, end, left, right, val)
        self.tree[node] = self.tree[2 * node] ^ self.tree[2 * node + 1]
    
    def _propagate(self, node, start, end):
        if self.lazy[node] != 0:
            self.tree[node] ^= self.lazy[node]
            if start != end:
                self.lazy[2 * node] ^= self.lazy[node]
                self.lazy[2 * node + 1] ^= self.lazy[node]
            self.lazy[node] = 0
    
    def __str__(self):
        return str(self.tree)
