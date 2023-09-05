import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

n=int(input())
p=ints()
l=[ints() for i in range(n)]
a=[[]for i in range(5)]
for i, j in l:
    a[i-1].append(j)

l=[]
for i in range(5):
    a[i]=sorted(a[i])[:p[i]]
    for j in a[i]:
        l.append((i, j))

ans=sum([i[1] for i in l])
for i in range(1, sum(p)):
    if l[i-1][0]==l[i][0]:
        ans+=l[i][1]-l[i-1][1]
    else:
        ans+=60
print(ans)
