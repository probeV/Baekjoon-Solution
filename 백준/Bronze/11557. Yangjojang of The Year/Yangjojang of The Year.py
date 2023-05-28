result=0
T=int(input())
for i in range(0,T):
    N=int(input())
    for j in range(0,N):
        S, L=input().split()
        if result<int(L):
            result=int(L)
            Ans=S
    print(Ans)