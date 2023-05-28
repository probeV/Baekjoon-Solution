import sys

N=int(sys.stdin.readline())
X=list(map(int, sys.stdin.readline().strip().split()))
A=sorted(list(set(X)))
a={}
result=0
for i in range(len(A)):
    a[A[i]]=result
    result=result+1
for i in range(N):
    print(a[X[i]], end=' ')