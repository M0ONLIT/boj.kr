import sys
from math import inf
sys.setrecursionlimit(10**7)
input=sys.stdin.readline
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

def input_graph(n):
    graph=[[] for i in range(n+1)]
    for i in range(n):
        a, b=ints()
        graph[a].append(b)
        graph[b].append(a)
    return graph

def ww1(node, mom, graph, visit, cnt):
    if len(graph[node])>2:
        return cnt, node
    visit[node]=1
    for nxt in graph[node]:
        if nxt!=mom:
            return ww1(nxt, node, graph, visit, cnt+1)

def ww2(node, graph, nodes, visit, tp, s):
    if visit[node]:
        return
    visit[node]=1

    cnt=0
    tp.append(nodes[node])
    for nxt in graph[node]:
        ww2(nxt, graph, nodes, visit, tp, s)

def data(graph):
    visit=[0]*(n+m+1)
    nodes=[0]*(n+m+1)
    tp=[]
    start=1
    for i in range(1, n+m+1):
        if len(graph[i])==1:
            value, start=ww1(i, -1, graph, visit, 0)
            nodes[start]=value
    ww2(start, graph, nodes, visit, tp, start)
    return tp

def make_pi(s):
    pi=[0]*len(s)
    idx=0
    for i in range(1, len(s)):
        while 1:
            if s[idx]==s[i]:
                pi[i]=idx+1
                idx+=1
                break
            elif idx==0:
                break
            idx=pi[idx-1]
    return pi

def match(t, p, dp):
    T, P=len(t), len(p)
    #ans=[]
    i_p=0
    for i_t in range(T):
        while 1:
            if t[i_t]==p[i_p]:
                if i_p==P-1:
                    #ans.append(i_t-P+2)
                    return 1
                else:
                    i_p+=1
                break
            if i_p==0:
                break
            i_p=dp[i_p-1]
    return 0

n, m=ints()
G1=input_graph(n+m)
G2=input_graph(n+m)

tp1=data(G1)
tp2=data(G2)
if len(tp1)!=len(tp2):
    print('Go to Minjun')
    exit()

pattern1=tp1
pattern2=tp1[::-1]
pi1=make_pi(pattern1)
pi2=make_pi(pattern2)

pattern3=tp2*2
if match(pattern3, pattern1, pi1) or match(pattern3, pattern2, pi2):
    print('Retry')
else:
    print('Go to Minjun')
