import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n  # Track the size of each set

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

n, q=ints()
sets=[set(ints()[1:]) for i in range(n)]
uf=UnionFind(n)
for i in range(q):
    query=ints()
    if query[0]==1:
        a, b=query[1]-1, query[2]-1
        if len(sets[a])==0:
            sets[a], sets[b]=sets[b], sets[a]
        elif len(sets[b])==0:
            pass
        else:
            if len(sets[a])>len(sets[b]):
                for i in sets[b]:
                    sets[a].add(i)
            else:
                for i in sets[a]:
                    sets[b].add(i)
                sets[a]=sets[b]
            sets[b]=set()
    else:
        print(len(sets[query[1]-1]))
