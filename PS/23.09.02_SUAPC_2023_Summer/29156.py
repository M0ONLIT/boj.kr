import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

n=int(input())
arr=[int(input()) for i in range(n)]
nu=arr[:]
for i in range(1, n):
    nu[i]+=nu[i-1]

l=int(input())

q=int(input())
for i in range(q):
    x=int(input())
    x-=1
    cal=nu[x]-arr[x]/2-l/2
    cal=min(nu[n-1]-l*1., cal)
    cal=max(0.0, cal)

    c1, c2=("%.6f"%cal).split('.')
    print(f'{c1}.{c2[:2]}')
