import sys
sys.setrecursionlimit(10**7)
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

n=Int()
p=[ints() for i in range(n)]
even, odd=[], []
for i in range(n):
    x, y=p[i]
    if (x+y)%2: odd.append(i+1)
    else: even.append(i+1)
if odd==[] or even==[]:
    print("NO")
else:
    print("YES")
    print(*even, *odd)
