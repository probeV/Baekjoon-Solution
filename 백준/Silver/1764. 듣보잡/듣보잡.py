N, M=map(int , input().split())
X,Y=set(),set()
result=0
for i in range(0,N):
    X.add(input())
for i in range(0,M):
    Y.add(input())
R=sorted(list(X & Y))
print(len(R))
for i in range(0,len(R)):
    print(R[i])           
