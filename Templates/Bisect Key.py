# Bisect key simulator. Useful for using bisect on sorted 2D-Arrays
class BisectKey(object):
    def __init__(self, iterable, key):
        self.iterable = iterable
        self.key = key

    def __len__(self):
        return len(self.iterable)

    def __getitem__(self, k):
        return self.key(self.iterable[k])