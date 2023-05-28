N, M=map(int, input().split())
X={}
for i in range(0,N):
    SITE, ID=input().split()
    X[SITE]=ID
Y=[]
for i in range(0,M):
    Y.append(input())
for i in range(0,M):
    print(X[Y[i]])