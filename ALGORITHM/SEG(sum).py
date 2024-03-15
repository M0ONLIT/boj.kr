class SegmentTree:
    def __init__(self, x):
        self.m = len(x)
        self.v = [0] * (self.m * 4)
        self.info = x
        self.make_tree(0, self.m - 1, 1)

    def make_tree(self, start, end, i):
        if start == end:
            self.v[i] = start
        else:
            mid = (start + end) // 2
            left = self.make_tree(start, mid, i * 2)
            right = self.make_tree(mid + 1, end, i * 2 + 1)
            self.v[i] = left + right
        return self.v[i]

    def sum(self, x, y):
        return self._sum(x, y, 0, self.m - 1, 1)

    def _sum(self, x, y, start, end, i):
        if y < start or x > end:
            return -1
        if x <= start and end <= y:
            return self.v[i]
        mid = (start + end) // 2
        left = self._sum(x, y, start, mid, i * 2)
        right = self._sum(x, y, mid + 1, end, i * 2 + 1)
        return left + right

    def insert(self, index, value):
        self._insert(index, value, 0, self.m - 1, 1)

    def _insert(self, index, value, start, end, i):
        if index < start or index > end:
            return
        if start == end == index:
            self.info[index] = value
            self.v[i] = index
            return
        mid = (start + end) // 2
        self._insert(index, value, start, mid, i * 2)
        self._insert(index, value, mid + 1, end, i * 2 + 1)
        self.v[i] = self.v[i * 2] + self.v[i * 2 + 1]

    def init(self, x = 0):
        self.v = [x] * (self.m * 4)
