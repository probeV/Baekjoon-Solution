import sys
input=sys.stdin.readline

def Sol():
    N=int(input())
    kind_coin=list(map(int, input().split()))
    M=int(input())

    sum=[0]*(M+1)
    sum[0]=1
    for i in range(N):
        for j in range(kind_coin[i],M+1):
            sum[j]+=sum[j-kind_coin[i]]
    print(sum[M])

T=int(input())
for _ in range(T):
    Sol()