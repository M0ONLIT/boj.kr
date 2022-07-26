import sys
input=sys.stdin.readline
ints=lambda: list(map(int, input().split()))
from collections import deque
inf=float("inf")
graph=[[0]*405 for i in range(405)]
cap=[[0]*405 for i in range(405)]
flow=[[0]*405 for i in range(405)]
back=[0]*405
backdo=[0]*405
memory=[0]*405
visit=[0]*405
def bfs():
    while Q:
        prev, now, dis, t=Q.popleft()
        if visit[now]:
            continue
        visit[now]=1
        back[now]=prev
        backdo[now]=t
        if now==2:
            return dis
        if memory[now]!=0 and not t:
            li=[memory[now]]
        else:
            li=graph[now]
        for i in li:
            val=cap[now][i]-flow[now][i]
            if val>0:
                Q.append((now, i, min(dis, val), flow[now][i]<0))
    return -1

n, p=ints()
for i in range(p):
    x, y=ints()
    if x==y:
        continue
    c=1
    
    graph[x].append(y)
    graph[y].append(x)
    cap[x][y]+=c
    cap[y][x]+=c

ans=0
while 1:
    Q=deque([(1, 1, inf, 0)])
    back=[0]*405
    backdo=[0]*405
    visit=[0]*405
    val=bfs()
    if val==-1:
        break
    ans+=val
    node=2
    while node!=back[node]:
        #print(node, end=' ')
        if not backdo[node]:
            memory[node]=back[node]
        flow[back[node]][node]+=val
        flow[node][back[node]]-=val
        node=back[node]
    #print()
print(ans)
