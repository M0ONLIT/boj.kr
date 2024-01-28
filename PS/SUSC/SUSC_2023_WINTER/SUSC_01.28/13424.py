import sys
from math import inf
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())
from queue import PriorityQueue

def input_graph(n, m):
    graph=[[] for i in range(n+1)]
    for i in range(m):
        a, b, c=ints()
        graph[a].append((b, c))
        graph[b].append((a, c))
    return graph

def d(node):
    ans=0
    visit=[0]*len(friend)
    Q=PriorityQueue()
    Q.put((0, node))

    while Q.qsize():
        dis, node=Q.pop()
        if visit[node]:
            continue
        visit[node]=1;

        if friend[node]:
            ans+=dis
        for nxt, d_nxt in graph[node]:
            Q.put((nxt, dis+d_nxt))
    return ans


def solve():
    global friend, graph
    n, m=ints()
    friend=[0]*(n+1)
    graph=input_graph(n, m)
    f=Int()
    for i in ints():
        friend[i]=1

    ans_node, ans_dis=None, inf
    for node in range(1, n+1):
        distance=d(node)
        if distance<ans_dis:
            ans_dis=distance
            ans_node=node

    print(ans_node)


for i in range(Int()):
    solve()
