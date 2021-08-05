# Union Find data structure **uses path compression**
#   Actions
#       - merge (union) two disjoint sets
#       - find which set an element belongs to
class UnionFind:
    def __init__(self, n: int):
        self.total_groups = n
        self.parents = [i for i in range(self.total_groups)]
        self.group_size = [1] * self.total_groups

    def find(self, x: int) -> int:
        root = x
        while self.parents[root] != root:
            root = self.parents[root]
        while self.parents[x] != root:
            temp = self.parents[x]
            self.parents[x] = root
            x = temp
        return root

    def union(self, x: int, y: int) -> None:
        rootX = self.find(x)
        rootY = self.find(y)
        if rootX != rootY:
            if self.group_size[rootX] < self.group_size[rootY]:
                self.group_size[rootY] += self.group_size[rootX]
                self.parents[rootX] = rootY
                self.group_size[rootX] = 0
                self.total_groups -= 1
            else:
                self.group_size[rootX] += self.group_size[rootY]
                self.parents[rootY] = rootX
                self.group_size[rootY] = 0
                self.total_groups -= 1
