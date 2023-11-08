from queue import PriorityQueue
import sys
from math import inf
sys.setrecursionlimit(10**7)
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

mx=5005
n, m=ints()
graph=[[]for i in range(mx)]
bit=[0]*mx
ans=inf

def dijks(starts, end=1):
    Q=PriorityQueue()
    visit=[0]*mx
    for node, dis in starts:
        Q.put((dis, node))
    while 1:
        dis, node=Q.get()
        if visit[node]:
            continue
        visit[node]=1
        if node==end:
            return dis
        for nxt, dis2 in graph[node]:
            if nxt==1 and chk[node]:
                continue
            Q.put((dis+dis2, nxt))

for i in range(m):
    a, b, c, d=ints()
    graph[a].append((b, c))
    graph[b].append((a, d))

near=[i[0] for i in graph[1]] #1번 노드와 인접한 것들
for i in range(len(near)):
    bit[near[i]]=i+1
for b in range(20):
    chk=[0]*mx
    start, end=[], []
    for node, dis in graph[1]:
        if bit[node] & (1<<b):
            start.append((node, dis))
            chk[node]=1
        else:
            end.append((node, dis))
    if start==[] or end==[]:
        break
    val=dijks(start)
    ans=min(val, ans)
    #print(start, end, val)

    chk=[0]*mx
    start, end=end, start
    for node, dis in start:
        chk[node]=1
    val=dijks(start)
    ans=min(val, ans)
    #print(start, end, val)

print(ans)
