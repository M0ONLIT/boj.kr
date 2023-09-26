import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

n, m=ints()
graph={i+1:[] for i in range(n)}

for i in range(m):
    a, b=ints()
    graph[b].append(a) #간선 방향 반대로

def dfs(node, ans, visit):
    if visit[node]:
        return
    visit[node]=1
    for i in graph[node]:
        dfs(i)
    ans.append(node)

def topology_sort(graph):
    ans=[]
    visit=[0]*(len(graph)+1)
    for i in range(n):
        dfs(i+1, ans, visit)
    return ans

print(*topology_sort(graph), sep=' ')
