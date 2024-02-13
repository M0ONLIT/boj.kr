import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

for tc in range(Int()):
    n, k=input().split()
    n=int(n)
    K=list(map(int, k)); k=int(k)
    s=sum(K)
    if n==1:
        print('6 3')
        continue
    for i in range(n):
        for j in range(1, 10):
            if (s-K[i]+j)%3==0 and K[i]!=j:
                temp=K[i]
                K[i]=j
                print(*K, sep='', end=' 3\n')
                K[i]=temp
                break
