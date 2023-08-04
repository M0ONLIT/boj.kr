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
