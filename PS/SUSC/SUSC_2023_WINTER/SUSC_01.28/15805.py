import sys
from math import sqrt
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

n=Int()
prev=-1
query=ints()
k=max(query)
parent=[0]*(k+1);
for node in query:
    if prev==-1 or parent[prev]!=node:
        parent[node]=prev
    prev=node
print(k+1)
print(*parent)
