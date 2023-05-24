N=int(input())
A=0
for i in range(0,N):
    X1, X2, X3=map(int, input().split())
    if X1==X2==X3:
        result=10000+X1*1000
    elif X1==X2:
        result=1000+X1*100
    elif X1==X3:
        result=1000+X1*100
    elif X2==X3:
        result=1000+X2*100
    else:
        X=[X1, X2, X3]
        X.sort()
        result=X[2]*100
    if A<result:
        A=result
print(A)