n=5000
dp=[0]*(n+1)
dp[0]=dp[1]=0
for i in range(2, n+1):
    dic={}
    for j in range(i-1):
        dic[dp[j]^dp[i-2-j]]=1
    ptr=0
    while dic.get(ptr)!=None:
        ptr+=1
    dp[i]=ptr

for i in range(int(input())):
    x=int(input())
    print('First' if dp[x] else 'Second')
