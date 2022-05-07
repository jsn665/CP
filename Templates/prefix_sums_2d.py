# 1 indexed. (-1, -1) to everything
class Prefix_Sums_2D:

    def __init__(self, grid):
        self.grid = grid
        n = len(grid)
        m = len(grid[0])
        self.res = [[0 for _ in range(m + 1)] for __ in range(n + 1)]
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                self.res[i][j] = self.res[i][j - 1] + self.res[i - 1][j] - self.res[i - 1][j - 1] + self.grid[i - 1][j - 1]


    # top left i, top left j, bottom right i, bottom right j
    def query(self, tli, tlj, bri, brj):
        return self.res[bri + 1][brj + 1] - self.res[tli][brj + 1] - self.res[bri + 1][tlj] + self.res[tli][tlj]
