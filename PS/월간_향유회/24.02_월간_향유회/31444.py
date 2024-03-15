import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n  # Track the size of each set
        self.team = [[{i}, set()] for i in range(n)]

    def find(self, x):
        if self.parent[x] == x:
            return x
        self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)

        t = (x in self.team[root_x][0] and y in self.team[root_y][0]) or \
            (x in self.team[root_x][1] and y in self.team[root_y][1])

        if root_x != root_y:
            if self.size[root_x] < self.size[root_y]:
                self.parent[root_x] = root_y
                self.size[root_y] += self.size[root_x]
                for i in range(2):
                    for val in self.team[root_x][i]:
                        self.team[root_y][(i+t)%2].add(val)
                    self.team[root_x][i].clear()
            else:
                self.parent[root_y] = root_x
                self.size[root_x] += self.size[root_y]
                for i in range(2):
                    for val in self.team[root_y][i]:
                        self.team[root_x][(i+t)%2].add(val)
                    self.team[root_y][i].clear()

    def equal(self, x, y):
        return self.find(x) == self.find(y)

    def count(self, x):
        root = self.find(x)
        return self.size[root]

n=Int()
mat=[ints() for i in range(n)]
arr=sorted([(mat[i][j], i, j) for i in range(n) for j in range(i+1, n)])
uf=UnionFind(n)
for val, i, j in arr:
    if uf.equal(i, j):
        a, b=uf.team[uf.find(i)]
        if (i in a and j in a) or (i in b and j in b):
            print(val)
            break
    else:
        uf.union(i, j)
