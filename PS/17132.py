n=int(input())
l=[list(map(int, input().split())) for i in range(n-1)]
l.sort(key=lambda x: -x[2])
union=list(range(n+1))
count=[1]*(n+1)
ans=0

def f(x):
    while 1:
        if x==union[x]:
            return x
        x=union[x]
    

for i, j, k in l:
    i, j=sorted((i, j)) #i가 더 작은거
    ans+=count[f(i)]*count[f(j)]*k
    count[f(i)]+=count[f(j)]
    union[i]=union[f(j)]=f(i)
print(ans)

#통과는 했으나 union find를 더 개선시킬 수 있음
