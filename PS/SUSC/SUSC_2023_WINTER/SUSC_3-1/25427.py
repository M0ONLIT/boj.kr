import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

n=Int()
s=input()
arr_d=[0]*n; cnt_d=0
arr_k=[0]*n; cnt_k=0
arr_s=[0]*n; cnt_s=0
arr_h=[0]*n; cnt_h=0
for i in range(n):
    if s[i]=='D':
        cnt_d+=1
    arr_d[i]=cnt_d

for i in range(n):
    if s[i]=='K':
        cnt_k+=arr_d[i]
    arr_k[i]=cnt_k

for i in range(n):
    if s[i]=='S':
        cnt_s+=arr_k[i]
    arr_s[i]=cnt_s

for i in range(n):
    if s[i]=='H':
        cnt_h+=arr_s[i]
    arr_h[i]=cnt_h
print(cnt_h)
