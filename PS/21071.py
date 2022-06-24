import sys
sys.setrecursionlimit(10**8)
input=sys.stdin.readline
nanugi=10**9+7

def mat(x,y):
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

def i_matrix(n):
    mat=[[0]*n for i in range(n)]
    for i in range(n):
        mat[i][i]=1
    return mat

def m_pow(L,r):
    if r==0:
        return i_matrix(len(L))
    if r==1:
        return L
    p=m_pow(L,r//2)
    if r%2==1:
        return mat(mat(p,p),L)
    else:
        return mat(p,p)

matrix=[
    [0, 1, 0, 0, 0, 0],
    [0, 0 ,1, 0, 0, 0],
    [3, 2, 1, 2, 0, 2],
    [0, 0, 0, 0, 1, 0],
    [0, 0, 0, 0, 0, 1],
    [1, 1, 0, 1, 0, 0]
]
a=[1, 1, 3, 0, 0, 1]
for i in range(len(a)):
    a[i]=[a[i]]

for i in range(int(input())):
    o=int(input())
    ans=mat(m_pow(matrix, o), a)[0][0]
    print(ans)
