import sys
input=sys.stdin.readline
ints=lambda: map(int, input().split())

n, k=ints()
L=[a,b,c,d]=list(ints())
A,B,C,D=[],[],[],[]
U=[A,B,C,D]
UU="ABCD"
pa=pb=pc=pd=0
for i in range(n):
    x,y=input().split()
    x=UU.index(x)
    U[x].append(int(y))
for i in U: i.sort()
for i in range(k):
    k=-1
    if len(A)>0 and (a+A[-1])*b*c*d>k:
        k=(a+A[-1])*b*c*d
        p=0
    if len(B)>0 and a*(b+B[-1])*c*d>k:
        k=a*(b+B[-1])*c*d
        p=1
    if len(C)>0 and a*b*(c+C[-1])*d>k:
        k=a*b*(c+C[-1])*d
        p=2
    if len(D)>0 and a*b*c*(d+D[-1])>k:
        k=a*b*c*(d+D[-1])
        p=3
    print(UU[p], U[p][-1])
    if p==0: a+=U[p][-1]
    if p==1: b+=U[p][-1]
    if p==2: c+=U[p][-1]
    if p==3: d+=U[p][-1]
    U[p].pop()

#eval, exec가 느리다는 사실을 깨달았다.
