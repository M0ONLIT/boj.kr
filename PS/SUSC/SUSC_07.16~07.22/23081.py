import sys

input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
inf=10**10

n=int(input())
a=[input() for i in range(n)] # 0 ~ n-1

def check(i, j):
  r=0
  for dx in (-1, 0, 1):
    for dy in (-1, 0, 1):
      m=1
      ans=0
      if dx==dy==0:
        continue
      while 0<=i+dx*m<n and 0<=j+dy*m<n:
        if a[i+dx*m][j+dy*m]=='W': ans+=1
        elif a[i+dx*m][j+dy*m]=='B': break
        else:
          ans=0
          break
        m+=1
      else: ans=0
      r+=ans
  return r


ans=[-inf]*3
for i in range(n):
  for j in range(n):
    if a[i][j]!='.': continue
    y=check(i, j)
    ans=max(ans, [y, -i, -j])
if ans[0]==0:
  print('PASS')
else:
  print(-ans[2], -ans[1])
  print(ans[0])
