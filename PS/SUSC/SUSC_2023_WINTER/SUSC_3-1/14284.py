from queue import PriorityQueue
import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

def input_graph(n, m):
    graph=[[] for i in range(n+1)]
    for i in range(m):
        a, b, c=ints()
        graph[a].append((b, c))
        graph[b].append((a, c))
    return graph

def d(s, e, graph):
    visit=[0]*(n+1)
    Q=PriorityQueue()

    while Q.qsize():
        d, node=Q.pop()
        if visit[v]: continue
        visit[v]=1
        if s==e:
            return d

        for nxt, dis in graph[v]:
            Q.append((d+dis, nxt))
    return None

n, m=ints()
graph=input_graph(n, m)
s, t=ints()
print(d(s, t, graph))
