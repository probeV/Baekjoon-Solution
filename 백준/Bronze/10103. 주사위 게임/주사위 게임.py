A1=A2=100
T=int(input())
for i in range(0,T):
        Y, K=map(int, input().split())
        if(Y>K):
            A2=A2-Y
        elif(Y<K):
            A1=A1-K
print(A1)
print(A2)