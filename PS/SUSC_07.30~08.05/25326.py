import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

n, m=ints()
p=[input().split() for i in range(n)]
for i in range(m):
    counter=0
    a, b, c=input().split()
    for x, y, z in p:
        if (x==a or a=='-') and (y==b or b=='-') and (z==c or c=='-'):
            counter+=1
    print(counter)
