class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))

    def find(self, x):
        if self.parent[x] == x:
            return x
        self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)

        if root_x > root_y:
            self.parent[root_y] = root_x
        elif root_x < root_y:
            self.parent[root_x] = root_y

    def equal(self, x, y):
        return self.find(x)==self.find(y)
