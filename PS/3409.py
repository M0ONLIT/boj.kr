import sys
input=lambda: sys.stdin.readline().strip()

dic={}
dic_bit={}
ptr=0

def dfs(node):
    if dic_bit.get(node)!=None:
        return dic_bit[node]

    if len(dic[node])==1:
        bit=0
        for i in dic[node][0]:
            bit|=1<<(ord(i)-97)
    else:
        bit=dfs(dic[node][0]) | dfs(dic[node][1])
    dic_bit[node]=bit
    return bit

def ww(node):
    global ptr
    if ptr==len(p):
        return
    if dic_bit[node] & (1<<(ord(p[ptr]-97))):
        if len(dic[node])==1:
            for i in dic[node][0]:
                if i==p[ptr]:
                    ptr+=1
                    if ptr==len(p):
                        return
        else:
            ww(dic[node][0])
            ww(dic[node][1])


for i in range(int(input())):
    n=int(input())
    for i in range(n):
        s=input().split()
        if len(s)==3:
            dic[s[0]]=s[2],
        else:
            dic[s[0]]=(s[2], s[4])
    for i in dic:
        dfs(i)
    t, p=input(), input()
    ww(t)
    print('YES' if ptr==len(p) else 'NO')

    dic.clear()
    dic_bit.clear()
    ptr=0
