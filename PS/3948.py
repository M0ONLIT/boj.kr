down,up=0,1
dp={}
def f(front,back,t):
    if front==back==0:
        return 1
    if (t==down and front==0) or (t==up and back==0):
        return 0
    if dp.get((front,back,t))!=None:
        return dp[(front,back,t)]
    if t==up:
        s=sum(f(front+i,back-i-1,not t)
              for i in range(back))
    else:
        s=sum(f(front-i-1,back+i,not t)
              for i in range(front))
        
    dp[(front,back,t)]=s
    return s

import sys
input=sys.stdin.readline
for i in range(int(input())):
    x=int(input())
    if x==1:
        print(x)
    else:
        print(f(x,0,down)+f(0,x,up))
