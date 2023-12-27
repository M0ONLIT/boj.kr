import sys
from collections import defaultdict
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
Int=lambda: int(input())

n=Int()
arr=ints()
dp=[defaultdict(int) for i in range(55)]
dp[0][0]=0
for i in range(n):
    for diff in dp[i]:
        dp[i+1][diff]=max(dp[i+1][diff], dp[i][diff])
        dp[i+1][diff+arr[i]]=max(dp[i+1][diff+arr[i]], dp[i][diff]+arr[i])
        dp[i+1][abs(diff-arr[i])]=max(dp[i+1][abs(diff-arr[i])], max(dp[i][diff], dp[i][diff]-diff+arr[i]))

print(dp[n][0] if dp[n][0] else -1)
