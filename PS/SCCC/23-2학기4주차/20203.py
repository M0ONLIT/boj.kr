import sys
sys.setrecursionlimit(10**8)
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

# 0~n번까지의 원소
class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n+1))

    def find(self, x):
        if self.parent[x] == x:
            return x
        self.parent[x] = self.find(self.parent[x])  # 경로 압축(Path Compression)을 통한 최적화
        return self.parent[x]

    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)

        if t[root_x] > t[root_y]:
            root_x, root_y = root_y, root_x
        self.parent[root_x] = root_y

    def equal(self, x, y):
        return self.find(x)==self.find(y)

n=int(input())
t=ints()
w=sorted(enumerate(t), key=lambda x: x[1])
tree={i:[] for i in range(n)}
for i in range(n-1):
    a, b=ints()
    tree[a-1].append(b-1)
    tree[b-1].append(a-1)

uf=UnionFind(100005)

ans=0
for node, weight in w:
    for nxt in tree[node]:
        if t[uf.find(nxt)]<=weight and not uf.equal(node, nxt):
            ans+=t[uf.find(node)]+t[uf.find(nxt)]
            uf.union(node, nxt)
print(ans)
