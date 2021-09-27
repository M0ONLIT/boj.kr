from math import *
import sys
input=sys.stdin.readline

MIN, MAX=-1_000_000, 1_000_000
loss=1e-8

def mibun(nums):
    POW=len(nums)-1
    L=[]
    for i in nums:
        L.append(POW*i)
        POW-=1
    L.pop()
    return L

def f(func, x):
    POW=len(func)-1
    ans=0
    for i in func:
        ans+=i*x**POW
        POW-=1
    return ans

def find_sol(minx, maxx, func):
    miny=f(func, minx)
    maxy=f(func, maxx)
    if miny>maxy:
        miny, maxy=maxy, miny
        minx, maxx=maxx, minx
    if loss<miny or maxy<-loss:
        return 'NO'
    midx=miny
    while abs(maxx-minx)>loss:
        midx=(minx+maxx)/2
        midy=f(func, midx)
        if -loss<midy<loss:
            minx=maxx=midx
            miny=maxy=midy
        elif midy>0:
            maxx=midx
            maxy=midy
        elif midy<0:
            minx=midx
            miny=midy
    midx=(minx+maxx)/2
    return midx

def find_sol_all(gugan, func):
    gugan=[MIN]+gugan+[MAX]
    solution=[]
    for i in range(len(gugan)-1):
        if abs(f(func, gugan[i]))<loss:
            ans=gugan[i]
        elif abs(f(func, gugan[i+1]))<loss:
            ans=gugan[i+1]
        else:
            ans=find_sol(gugan[i], gugan[i+1], func)
        solution.append(ans)
    if abs(f(func, gugan[-1]))<loss:
        solution.append(gugan[-1])

    for i in range(len(solution)):
        for j in range(i+1, len(solution)):
            if solution[i]=='NO' or solution[j]=='NO':
                continue
            if abs(solution[i]-solution[j])<1e-5:
                solution[j]='NO'
                continue
            break
    solution=list(filter(lambda x: x!='NO', solution))
    solution=list(map(lambda x: round(x, 10), solution))
    return solution


for i in range(int(input())):
    fx=list(map(int, input().split()))
    ffx=mibun(fx) #도함수
    fffx=mibun(ffx) #이계도함수

    sol_fffx=find_sol_all([], fffx)
    sol_ffx=find_sol_all(sol_fffx, ffx)
    sol_fx=find_sol_all(sol_ffx, fx)
    for i in sol_fx: print(round(i, 5), end=' ')
    print()
