import sys
from math import *
sys.setrecursionlimit(3*10**5)
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n

    def find(self, x):
        if self.parent[x] == x:
            return x
        self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)

        if root_x != root_y:
            if self.size[root_x] < self.size[root_y]:
                self.parent[root_x] = root_y
                self.size[root_y] += self.size[root_x]
            else:
                self.parent[root_y] = root_x
                self.size[root_x] += self.size[root_y]

    def equal(self, x, y):
        return self.find(x) == self.find(y)

    def count(self, x):
        root = self.find(x)
        return self.size[root]

def g(x):
    return x*(x-1)//2

n, m=ints()
ans=n
uf=UnionFind(n+1)
for i in range(m):
    a, b=ints()
    if not uf.equal(a, b):
        ans-=g(uf.count(a))+g(uf.count(b))
        uf.union(a, b)
        ans+=g(uf.count(a))
    print(ans)
