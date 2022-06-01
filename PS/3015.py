n=int(input())
stack=[]
ans=0
def bs(x):
    start, end=0, len(stack)-1
    while start<end:
        mid=(start+end)//2
        if x<stack[mid]:
            start=mid+1
        else:
            end=mid
    return start
    
for i in range(n):
    x=int(input())
    while 1:
        if len(stack)==0:
            stack.append(x)
            break
        top=stack[-1]
        if top<x:
            ans+=1
            stack.pop()
        elif top==x:
            ans+=len(stack)-bs(x)
            ans+=stack[0]!=x
            stack.append(x)
            break
        else:
            ans+=1
            stack.append(x)
            break
    #print(stack, ans)
print(ans)
