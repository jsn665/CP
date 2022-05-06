class Hashing:

    def __init__(self, text):
        n = len(text)
        self.p = 31  # 53 for lowercase and uppercase, 31 for only of one type
        self.MOD = int(1e9) + 9
        self.hash = [0] * (n + 1)
        self.p_pow = [1] * n
        for i in range(1, n):
            self.p_pow[i] = self.p_pow[i - 1] * self.p % self.MOD

        for i in range(n):
            c = ord(text[i]) - 96
            self.hash[i + 1] = (self.hash[i] * self.p + c) % self.MOD

    # [L,R] inclusive
    def get_hash(self, L, R):
        return (self.hash[R + 1] - self.hash[L] * self.p_pow[R - L + 1]) % self.MOD
