from fractions import Fraction
import sys

input=sys.stdin.readline
ints=lambda: list(map(int, input().split()))

def minusList(a, b, idx): #b-a
    #a[idx]*x=b[idx]
    piv=b[idx]/a[idx]
    return [b[i]-piv*a[i] for i in range(n+1)]

n=int(input())
matrix=[ints() for i in range(n)]
ans=[0]*n
for i in range(n):
    for j in range(i+1, n):
        matrix[j]=minusList(matrix[i], matrix[j], i)
#print(*matrix, sep='\n')

for i in range(n)[::-1]:
    p=matrix[i][-1]
    for j in range(i+1, n):
        p-=matrix[i][j]*ans[j]
    ans[i]=p/matrix[i][i]
for i in ans:
    print(int(round(i, 0)), end=' ')
