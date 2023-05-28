N=int(input())
X=map(int,  input().split())
X=sorted(X)
result=0
for i in range(0,N):
    for j in range(0,i+1):
        result=X[j]+result
print(result)