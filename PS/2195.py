s, p=input(), input()
dic={}
def append(x):
    node=dic
    for i in x:
        if node.get(i)==None:
            node[i]={}
        node=node[i]
        
def find():
    global ptr
    node=dic
    while p[ptr] in node:
        node=node[p[ptr]]
        ptr+=1
        if ptr==len(p):
            break
    
for i in range(len(s)):
    append(s[i:])

ans=ptr=0
while ptr<len(p):
    ans+=1
    find()
print(ans)
