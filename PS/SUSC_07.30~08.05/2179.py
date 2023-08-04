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

'''
풀이법: 정렬
이 문자열들을 사전 순으로 정렬했을 때, 정답이 되는 두 문자열은 붙어 있을 것이라는 아이디어에서 출발하였다.
그러나 입력 받은 순서대로 정답이 결정되기에 일단 정답이 될 수 있는 집합들을 만들어 나중에 다시 인덱스 순으로 정렬하였다.

시간복잡도: O(n) 하나의 집합 안에 들어 있을 수 있는 정답 후보는 26개가 최대이므로
이를 정렬하는 경우는 시간복잡도에 고려하지 않아도 된다.
'''
