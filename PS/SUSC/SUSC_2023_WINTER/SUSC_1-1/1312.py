a, b, n=map(int, input().split())
a%=b
for i in range(n):
    a*=10
    ans=a//b
    a%=b
print(ans)
