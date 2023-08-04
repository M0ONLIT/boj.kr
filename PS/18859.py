import sys
sys.setrecursionlimit(10**7)
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))
inf=float('inf')

n=int(input())
l=sorted(ints())
l=list(map(lambda x: x-l[0], l))

def eq(p): #숫자 4개가 등차수열인지
    ans=set()
    for i in range(len(p)-1):
        ans.add(p[i]-p[i+1])
    return len(ans)==1

left=0
right=l[1]

right_d=l[1]
left_d=inf


def dfs(left, right, left_d, right_d, idx):
    if idx==n:
        return 1
    if l[idx]==right+right_d:
        ans=dfs(left, l[idx], left_d, right_d, idx+1)
    elif l[idx]==left+left_d:
        ans=dfs(l[idx], right, left_d, right_d, idx+1)
    else:
        if left_d==inf:
            if left==0:
                ans=dfs(l[idx], right, left_d, right_d, idx+1)
            else:
                if l[idx]==2*left:
                    ans=dfs(l[idx], right, left, right_d, idx+1)
                else:
                    br=[0]+sorted([right, left])+[l[idx]]
                    if eq(br):
                        ans=dfs(l[idx], right-right_d, br[1], right_d, idx+1)
                    else:
                        ans=0
        else:
            lbr=[left, right, l[idx]]
            rbr=[right, left, l[idx]]
            if eq(lbr) and right-left==left_d:
                ans=dfs(l[idx], right-right_d, left_d, right_d, idx+1)
            elif eq(rbr) and left-right==right_d:
                ans=dfs(left-left_d, l[idx], left_d, right_d, idx+1)
            else:
                ans=0
    return ans

ans=bool(dfs(left, right, left_d, right_d, 2) and right)
print(['No', 'Yes'][ans])
