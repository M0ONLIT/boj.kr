import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

n, m=ints()
friend=[0]*(n+1)
l=ints()
for i in ints():
    friend[i]=1

for i in range(len(l)):
    l[i]=friend[l[i]]

print(m-sum(l[:m]))
