### templete
import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
###


n, m=ints()
arr=sorted(ints(), reverse=1)

s=0
for i in range(n):
    if arr[i]-i<0:
        break
    s+=arr[i]-i
print(s)
