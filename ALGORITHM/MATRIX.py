import sys
sys.setrecursionlimit(10**8)
input=sys.stdin.readline
nanugi=10**9+7

def multiply_matrix(x,y):
    xc, xr=len(x), len(x[0])
    yc, yr=len(y), len(y[0])
    assert xr==yc
    mat=[[0]*yr for i in range(xc)]
    for i in range(xc):
        for j in range(yr):
            for k in range(xr):
                mat[i][j]+=x[i][k]*y[k][j]
            mat[i][j]%=nanugi
    return mat

def identity_matrix(n):
    mat=[[0]*n for i in range(n)]
    for i in range(n):
        mat[i][i]=1
    return mat

def m_pow(L, r):
    if r==0:
        return identity_matrix(len(L))
    p=m_pow(L, r//2)
    if r%2==1:
        return multiply_matrix(multiply_matrix(p, p), L)
    else:
        return multiply_matrix(p, p)
