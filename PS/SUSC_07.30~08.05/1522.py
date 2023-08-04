S='0'+input()
a=b=0
t=1000
A,B=[0],[0]
for i in S[1:]:
    if i=='a':
        a+=1
    else:
        b+=1
    A.append(a)
    B.append(b)
for i in range(len(S)):
    for j in range(i+1,len(S)):
        if b-(B[j]-B[i])==A[j]-A[i]:
            t=A[j]-A[i] if A[j]-A[i]<t else t
        if a-(A[j]-A[i])==B[j]-B[i]:
            t=B[j]-B[i] if B[j]-B[i]<t else t
print(t)

'''
풀이법: 누적합 배열
구간 i, j를 정한다. 이때 i~j까지의 구간을 알파벳 하나로만 만들어 보려고 한다.
i~j의 구간에 있는 a의 개수와 나머지 구간의 b의 개수가 같다면 이는 i~j구간을 모두 a로 만들 수 있다는 뜻이다.
b에 관해서도 한번 더 해본다.

i~j 구간에 있는 a의 개수는 누적합 배열(A)을 이용하면 O(1)에 구할 수 있다.

시간복잡도: O(n^2) 모든 0<=i<j<=n 을 만족하는 쌍을 대입해봐야 하기 때문이다.
'''
