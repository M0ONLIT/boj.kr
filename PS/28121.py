import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n  # Track the size of each set
        self.check = [0] * n
        self.team = [[{i}, set()] for i in range(n)]

    def find(self, x):
        if self.parent[x] == x:
            return x
        self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        global ans
        root_x = self.find(x)
        root_y = self.find(y)

        t = (x in self.team[root_x][0] and y in self.team[root_y][0]) or \
            (x in self.team[root_x][1] and y in self.team[root_y][1])

        if self.check[root_x] and not self.check[root_y]:
            self.parent[root_y] = root_x
            ans+=self.size[root_y]
            return
        if not self.check[root_x] and self.check[root_y]:
            self.parent[root_x] = root_y
            ans+=self.size[root_x]
            return

        if root_x != root_y:
            if self.size[root_x] < self.size[root_y]:
                self.parent[root_x] = root_y
                self.size[root_y] += self.size[root_x]
                for i in range(2):
                    for val in self.team[root_x][i]:
                        self.team[root_y][(i+t)%2].add(val)
                    self.team[root_x][i].clear()
                self.check[root_y] |= self.check[root_x]
            else:
                self.parent[root_y] = root_x
                self.size[root_x] += self.size[root_y]
                for i in range(2):
                    for val in self.team[root_y][i]:
                        self.team[root_x][(i+t)%2].add(val)
                    self.team[root_y][i].clear()
                self.check[root_x] |= self.check[root_y]

    def equal(self, x, y):
        return self.find(x) == self.find(y)

    def count(self, x):
        root = self.find(x)
        return self.size[root]

n, q=ints()
uf=UnionFind(n+1)
ans=0
for _ in range(q):
    i, j=ints()
    if uf.equal(i, j):
        root=uf.find(i)
        a, b=uf.team[root]
        if (i in a and j in a) or (i in b and j in b): #i, j가 같은 팀이면
            if not uf.check[root]:
                uf.check[root]=1
                ans+=uf.count(root)
    else:
        uf.union(i, j)
    print(ans)
