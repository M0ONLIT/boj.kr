def solve(s):
    n=list(map(int, s))
    length=len(n)
    mx=(length-1)//2+1
    ans=0

    dp={}
    def ww(idx, t):
        if idx==mx: #2: 클수도 1: 같다 0:작다
            return t<=1
        if t==0:
            return 10**(mx-idx)
        if dp.get((idx, t))!=None:
            return dp[(idx, t)]
        ans=0
        for i in range(10):
            if i==0 and idx==0:
                continue
            if i<n[idx]:
                ans+=ww(idx+1, 0)
            elif i==n[idx]:
                if i<n[length-1-idx]:
                    ans+=ww(idx+1, 1)
                elif i==n[length-1-idx]:
                    ans+=ww(idx+1, t)
                else:
                    ans+=ww(idx+1, 2)
            else:
                break
        dp[(idx, t)]=ans
        return ans

    for i in range(1, length):
        ans+=9*10**((i-1)//2)
    ans+=ww(0, 1)
    print(ans)

solve(input())
