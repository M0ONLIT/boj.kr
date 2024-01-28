import sys
from collections import deque

input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

n, m, k, x=ints()
graph={i+1:[] for i in range(n)}
visit=[0]*(n+1)

ans=[]

for i in range(m):
    a, b=ints()
    graph[a].append(b)

D=deque([(x, 0)])
while len(D)>0:
    node, dis=D.popleft()
    if visit[node]:
        continue
    visit[node]=1

    if dis==k:
        ans.append(node)
        continue

    for i in graph[node]:
        D.append((i, dis+1))

if ans: print(*sorted(ans), sep='\n')
else: print(-1)
