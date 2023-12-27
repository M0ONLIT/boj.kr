i=input
n,m=map(int,i().split())
print(sum([i().count('O')>m*.5for _ in '*'*n]))
