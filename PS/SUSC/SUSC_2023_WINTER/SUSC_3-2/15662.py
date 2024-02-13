import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

N=Int()
rt=[0]*N
gear=[list(map(int, input())) for i in range(N)]
for _ in range(Int()):
    n, k=ints(); n-=1
    rt[n]=k
    for i in range(n)[::-1]:
        if gear[i][2]!=gear[i+1][-2]:
            rt[i]=-rt[i+1]
        else:
            break
    for i in range(n+1, N):
        if gear[i][-2]!=gear[i-1][2]:
            rt[i]=-rt[i-1]
        else:
            break
    for i in range(N):
        if rt[i]==1:
            temp=gear[i].pop()
            gear[i].insert(0, temp)
        elif rt[i]==-1:
            temp=gear[i].pop(0)
            gear[i].append(temp)
        rt[i]=0
print(sum([gear[i][0] for i in range(N)]))
