import sys
from copy import deepcopy as copy
sys.setrecursionlimit(10**8)
n=2
a, b, nanugi=map(int, input().split())

def mat(x,y):
    mat=[[0]*n for i in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                mat[i][j]+=x[i][k]*y[k][j]
            mat[i][j]%=nanugi
    return mat

def m_pow(L,r):
    if r==1:
        return L
    p=m_pow(L,r//2)
    if r%2==1:
        return mat(mat(p,p),L)
    else:
        return mat(p,p)

matrix=[
    [0, -1],
    [1, a]
]
ans=m_pow(matrix, b)
print((ans[0][0]*2+ans[1][0]*a)%nanugi)
