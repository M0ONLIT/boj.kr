class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))

    def find(self, x):
        if self.parent[x] == x:
            return x
        self.parent[x] = self.find(self.parent[x])  # 경로 압축(Path Compression)을 통한 최적화
        return self.parent[x]

    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)

        if root_x > root_y:
            self.parent[root_y] = root_x
        elif root_x < root_y:
            self.parent[root_x] = root_y
