import sys
sys.setrecursionlimit(2*10**5)
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

nanugi=1000003
n, x, y, k=ints()
vertex=[]
arr=[]
dic={}
for i in range(n):
    s=input()
    for j in range(n):
        w=int(s[j])
        if w!=0:
            vertex.append((i, j, w))

def f(start, end, k):
    if k<0: return 0
    if k==0: return start==end
    if dic.get((start, end, k))!=None: return dic[(start, end, k)]

    ans=0
    for i, j, w in vertex:
        s=(k+1)//2-w
        for x in range(w):
            ans+=f(start, i, s+x)*f(j, end, k-s-x-w)
            #print(k, s+x, w, k-s-x-w)
            ans%=nanugi
    dic[(start, end, k)]=ans
    return ans

print(f(x-1, y-1, k))
