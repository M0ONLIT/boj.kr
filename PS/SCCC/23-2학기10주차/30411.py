ints=lambda: list(map(int, input().split()))
n, k=ints()

x, y=(n+1)//2, n//2
def gen():
    X=range(x)
    Y=range(x, x+y)
    for i in X:
        for j in Y:
            yield (i+1, j+1)

if x*y>=k:
    iter=gen()
    print("YES")
    for i in range(k):
        print(*next(iter))
else:
    print("NO")
