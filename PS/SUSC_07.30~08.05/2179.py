import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

def comp(x, y):  #공통 문자열 개수 구하는 함수
    cnt=0
    for i in range(min(len(x), len(y))):
        if x[i]!=y[i]:
            break
        cnt+=1
    return cnt

n=int(input())
arr=[input() for i in range(n)]
s=sorted([(arr[i], i) for i in range(n)])
maximum=-1
L=[]

for i in range(n-1):
    ans=comp(s[i][0], s[i+1][0])
    if ans>maximum:
        maximum=ans
        L=[]
        L.append(set())
        L[-1].add(s[i][1])
        L[-1].add(s[i+1][1])
    elif ans==maximum:
        if s[i][1] in L[-1]:
            L[-1].add(s[i+1][1])
        else:
            L.append(set())
            L[-1].add(s[i][1])
            L[-1].add(s[i+1][1])

for i in range(len(L)):
    L[i]=sorted(L[i])[:2]
x, y=min(L)
print(arr[x])
print(arr[y])
