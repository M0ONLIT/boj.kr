from queue import PriorityQueue
input=__import__('sys').stdin.readline
q=PriorityQueue()

l=[]
for i in range(int(input())):
    l.append(sorted(map(int, input().split())))
l.sort(key=lambda x: x[1])
d=int(input())
ans=0
for x, y in l:
    q.put(x)
    while 1:
        if q.qsize()==0:
            break
        p=q.get()
        if y-d<=p:
            q.put(p)
            break
    ans=max(ans, q.qsize())
print(ans)

#덱을 이용한 O(N)풀이도 있다
