import sys
input=sys.stdin.readline
from collections import deque
inf=float("inf")
graph={}
cap={}
flow={}
back={}
visit={}
def bfs():
    while Q:
        prev, now, dis=Q.popleft()
        if visit.get(now):
            continue
        visit[now]=1
        back[now]=prev
        if now=='Z':
            return dis
        for i in graph[now]:
            val=cap[(now, i)]-flow[(now, i)]
            if val>0:
                Q.append((now, i, min(dis, val)))
    return -1

n=int(input())
for i in range(n):
    x, y, c=input().split()
    c=int(c)
    
    if graph.get(x)==None:
        graph[x]=[]
    if graph.get(y)==None:
        graph[y]=[]
    graph[x].append(y)
    graph[y].append(x)
    if cap.get((x, y))==None:
        cap[(x, y)]=cap[(y, x)]=0
    cap[(x, y)]+=c
    cap[(y, x)]+=c
    flow[(x, y)]=flow[(y, x)]=0

ans=0
while 1:
    Q=deque([('', 'A', inf)])
    visit.clear()
    back.clear()
    val=bfs()
    if val==-1:
        break
    ans+=val
    node='Z'
    while back[node]:
        flow[(back[node], node)]+=val
        flow[(node, back[node])]-=val
        node=back[node]
print(ans)
