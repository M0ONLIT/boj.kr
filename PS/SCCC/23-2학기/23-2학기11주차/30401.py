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

def tree_to_int(tree, node, mom, code, value):
    return int(tree_to_hash(tree, node, mom, code, value), 2)

def tree_to_hash(tree, node, mom, code, value):
    sons=[]
    for nxt in tree[node]:
        if nxt!=mom and code==value[nxt]:
            sons.append(tree_to_hash(tree, nxt, node, code, value))
    sons.sort()

    return '1'+''.join(sons)+'0'

def data(graph):
    value=[0]*(n+m+1)
    isroot=[0]*(n+m+1)
    visit=[0]*(n+m+1)
    visit2=[0]*(n+m+1)
    s=-1 #init

    def ww(node, mom=-1):
        nonlocal s, value, visit
        if visit[node]:
            return 0
        visit[node]=1

        for nxt in graph[node]:
            if nxt==mom:
                continue
            if visit[nxt] and s==-1:
                value[node]=-1
                isroot[node]=1
                s=nxt
                continue
            ww(nxt, node)
            if value[nxt]==-1 and nxt!=s:
                isroot[node]=1
                value[node]=-1

    def ww2(node, tp):
        nonlocal visit2
        if visit2[node] or not isroot[node]:
            return
        visit2[node]=1
        tp.append(tree_to_int(graph, node, -1, node, value))
        for nxt in graph[node]:
            ww2(nxt, tp)

    def dfs(node, mom, cnt):
        nonlocal value
        value[node]=cnt
        for nxt in graph[node]:
            if nxt==mom:
                continue
            dfs(nxt, node, cnt)

    ww(1)
    for i in range(1, n+m+1):
        if value[i]==-1:
            for node in graph[i]:
                if value[node]==0:
                    dfs(node, i, i)
            value[i]=i

    tp=[]
    ww2(s, tp)
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

def match(t, p):
    dp=make_pi(p)
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
    #return ans
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
pattern3=tp2*2
if match(pattern3, pattern1) or match(pattern3, pattern2):
    print('Retry')
else:
    print('Go to Minjun')
