import sys
from fractions import Fraction as frac
from math import *
sys.setrecursionlimit(10**6)
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

def input_graph(n, m):
    graph=[[] for i in range(n+1)]
    for i in range(m):
        a, b=ints()
        graph[a].append(b)
        graph[b].append(a)
    return graph

def articulation_points_bool(n, graph): #단절점(정점개수, 그래프)
    visit=[0]*(n+1) #방문 순서 표기(안했으면 0)
    children=[0]*(n+1) #인접한 자식 정점 개수
    min_node=[0]*(n+1) #정점i에서 갈 수 있는 가장 작은 노드
    ans=[0]*(n+1) #1이면 단절점
    stack=[] #방문 순서대로 정점 번호 삽입
    cnt=1 #방문 순서 번호

    def ordering(node, check=0): #순서(정점 번호, check->루트인지 확인)
        nonlocal cnt, visit, ans
        minvalue=node
        stack.append(node)
        visit[node]=cnt
        cnt+=1
        for nxt in graph[node]:
            if visit[nxt]:
                temp=nxt
            else:
                children[node]+=1
                temp=ordering(nxt)
                if visit[temp]>=visit[node] and not check:
                    ans[node]=1
            minvalue=min(minvalue, temp, key=lambda x: visit[x])

        if children[node]>1 and check:
            ans[node]=2
        min_node[node]=minvalue
        return minvalue

    for i in range(1, n+1):
        if not visit[i]:
            ordering(i, 1)
    #print(ans, visit, min_node)
    return ans

v, e=ints()
graph=input_graph(v, e)
vec=articulation_points_bool(v, graph)
cnt, ans=0, []
for i in range(1, v+1):
    if vec[i]:
        cnt+=1
        ans.append(i)
print(cnt)
print(*ans)
