'''
Sparse Table implementation for either Range Minimum Queries or Range Maximum Queries
'''
class SparseTable:
    '''
    :param A: The array to be queried
    :param method: python function to be passed. e.g. min or max function
    :returns: None
    '''
    def __init__(self,A, method):
        self.method = method
        N = len(A)
        self.logs = [0] * (N + 1)
        self.logs[1] = 0
        for i in range(2, N + 1):
            self.logs[i] = self.logs[i // 2] + 1

        K = self.logs[N]
        self.st = [[0 for _ in range(N)] for __ in range(K + 1)]
        for i in range(N):
            self.st[0][i] = (A[i], i)

        for i in range(1, K + 1):
            j = 0
            while j + (1 << i) - 1 < N:
                self.st[i][j] = self.method(self.st[i - 1][j], self.st[i - 1][j + (1 << (i - 1))], key= lambda x : x[0])
                j += 1

    '''
    :param L: left bound of the subarray to be queried
    :param R: right bound of the subarray to be queried (inclusive)
    :returns: tuple with (method result, index)
    '''
    def query(self, L, R):
        K = self.logs[R - L + 1]
        return self.method(self.st[K][L], self.st[K][R - (1 << K) + 1], key= lambda x : x[0])
