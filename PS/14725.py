import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**8)

dic={}
def append():
    node=dic
    while l:
        x=l.pop()
        if node.get(x)==None:
            node[x]={}
        node=node[x]
        
def ans(node, d):
    for i in sorted(node):
        print('--'*d, i, sep='')
        ans(node[i], d+1)
    
for i in range(int(input())):
    l=input().split()[1:][::-1]
    append()
ans(dic, 0)
