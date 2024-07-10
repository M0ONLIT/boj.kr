class segment_tree:
    def __init__(self, n):
        if isinstance(n, int):
            self.SZ = n
            self.T = [0] * (self.SZ * 2)
        else:
            x = n
            self.SZ = len(x)
            self.T = [0] * (self.SZ * 2)
            for i in range(self.SZ):
                self.T[i + self.SZ] = x[i]
            for i in range(self.SZ - 1, 0, -1):
                self.T[i] = self.T[i * 2] + self.T[i * 2 + 1]

    def insert(self, x, v):  # x번째 수를 v로 지정, x는 0 이상 SZ 미만
        x += self.SZ
        self.T[x] = v
        while x > 1:
            x //= 2
            self.T[x] = self.T[x * 2] + self.T[x * 2 + 1]

    def sum(self, l, r):  # [l, r] 구간의 합
        ans = 0
        l += self.SZ
        r += self.SZ
        while l <= r:
            if l % 2 == 1:
                ans += self.T[l]
                l += 1
            if r % 2 == 0:
                ans += self.T[r]
                r -= 1
            l //= 2
            r //= 2
        return ans

    def init(self):
        self.T = [0] * (self.SZ * 2)
