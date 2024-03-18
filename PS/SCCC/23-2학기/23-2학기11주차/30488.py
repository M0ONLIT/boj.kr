import sys
from queue import PriorityQueue as PQ
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

n, m=ints()
graph=[[]for i in range(n+1)]
start, middle=ints()

for i in range(m):
    a, b, c=ints()
    graph[a].append((b, c))
    graph[b].append((a, c))

visit=[0]*(n+1)
distance=[0]*(n+1)
c=[0]*(n+1)
ans=[]
Q=PQ()
Q.put((0, 0, start))

while Q.qsize()>0:
    num, check, node=Q.get()
    if visit[node]:
        continue
    visit[node]=1
    distance[node]=num
    c[node]=node==middle or check

    for nxt, d in graph[node]:
        Q.put((num+d, c[node], nxt))

cnt=0
for i in range(1, n+1):
    if distance[i]==distance[middle]*2 and c[i]:
        print(i, end=' ')
        cnt+=1
if cnt==0:
    print('*')
