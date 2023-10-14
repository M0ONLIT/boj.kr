import sys
input=lambda: sys.stdin.readline().strip()
ints=lambda: list(map(int, input().split()))

s=input()
stack=[]
for i in s:
    if i=='f' or i=='g':
        stack.append(i)
    else:
        stack.append(0)
        while len(stack)>1:
            if stack[-2]=='g':
                val=stack.pop()
                stack.pop()
                stack.append(val+1)
            elif len(stack)>=3 and type(stack[-2])==int and stack[-3]=='f':
                val1=stack.pop()
                val2=stack.pop()
                stack.pop()
                stack.append(min(val1, val2))
            else:
                break
print(stack[0] if len(stack)==1 and type(stack[0])==int else -1)
