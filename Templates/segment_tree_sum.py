# Segment Tree Sum Queries
'''
@:param: n -> size of input
@:param: arr -> array to build
'''
class SegmentTree:
    def __init__(self, n, arr):
        self.N = n
        self.tree = [0] * (4 * self.N)
        def build(root, rootL, rootR):
            if rootL == rootR:
                self.tree[root] = arr[rootL]
                return
            left_child = 2 * root + 1
            right_child = 2 * root + 2
            mid = (rootL + rootR) // 2
            build(left_child, rootL, mid)
            build(right_child, mid + 1, rootR)
            self.tree[root] = self.tree[left_child] + self.tree[right_child]
        if len(arr):
            build(0, 0, self.N - 1)


    # query range [L,R] **R is inclusive**
    def query(self, L, R):
        return self._query_helper(L, R, 0, 0, self.N - 1)

    def _query_helper(self, L, R, root, rootL, rootR):
        if rootL >= L and rootR <= R:
            return self.tree[root]
        elif rootL > R or rootR < L:
            return 0
        left_child = 2 * root + 1
        right_child = 2 * root + 2
        mid = (rootL + rootR) // 2
        return self._query_helper(L, R, left_child, rootL, mid) + self._query_helper(L, R, right_child, mid + 1, rootR)

    # point update
    def update(self, index, value):
        return self._update_helper(index, 0, 0, self.N - 1, value)

    def _update_helper(self, index, root, rootL, rootR, value):
        if rootL == rootR:
            self.tree[root] = value
            return
        left_child = 2 * root + 1
        right_child = 2 * root + 2
        mid = (rootL + rootR) // 2
        if index >= rootL and index <= mid:
            self._update_helper(index, left_child, rootL, mid, value)
        else:
            self._update_helper(index, right_child, mid + 1, rootR, value)
        self.tree[root] = self.tree[left_child] + self.tree[right_child]
