import sys
from bisect import bisect_left
sys.setrecursionlimit(10**8)
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

mx=200005
def input_tree(n):
    tree=[[] for i in range(n+1)]
    for i in range(n-1):
        a, b=ints()
        tree[a].append(b)
        tree[b].append(a)
    return tree

n=Int()
tree=input_tree(n)
s=[0]*(n+1)
a, b=set(), set()

def dfs(node, mom):
    ans=1
    for nxt in tree[node]:
        if nxt==mom: continue
        ans+=dfs(nxt, node)
    s[node]=ans
    return ans

def dfs2(x, node, mom): # x는 집합
    x.add(s[node])
    for nxt in tree[node]:
        if nxt==mom: continue
        dfs2(x, nxt, node)

def find_centroid(node, mom):
    for nxt in tree[node]:
        if nxt==mom: continue
        if s[nxt]>n/2:
            return find_centroid(nxt, node)
    return node

dfs(1, None)
root=find_centroid(1, None)
dfs(root, None)

tree[root].sort(key=lambda x: s[x], reverse=True)
dfs2(a, tree[root][0], root)
for node in tree[root][1:]:
    dfs2(b, node, root)

A, B=sorted(a), sorted(b)
ans=mx

for i in A:
    value=(n-i)/2
    IDX=bisect_left(B, value)

    idx=IDX
    if idx==len(B):
        idx-=1
    L=[i, B[idx], n-i-B[idx]]
    ans=min(max(L)-min(L), ans)

    idx=IDX-1
    if idx==-1:
        idx+=1
    L=[i, B[idx], n-i-B[idx]]
    ans=min(max(L)-min(L), ans)

for i in A:
    value=(n+i)/2
    IDX=bisect_left(A, value)

    idx=IDX
    if idx==len(A):
        idx-=1
    L=[i, A[idx]-i, n-A[idx]]
    ans=min(max(L)-min(L), ans)

    idx=IDX-1
    if idx==-1:
        idx+=1
    L=[i, A[idx]-i, n-A[idx]]
    ans=min(max(L)-min(L), ans)
print(ans)
