import sys
sys.setrecursionlimit(10**8)
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

s=input()
ph=pg=0
for i in s:
    if i in 'HAPPY':
        ph+=1
    if i in 'SAD':
        pg+=1
if ph==pg==0:
    h=.5
else:
    h=ph/(ph+pg)
print('%.2f'%(h*100+1e-9))
