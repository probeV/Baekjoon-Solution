import sys
input=sys.stdin.readline

def Sol():
    N, K = map(int, input().split())
    data=[]

    for i in range(N):
        W,V=map(int, input().split())
        data.append([W,V])

    sum=[[0]*(N+1) for _ in range(K+1)]

    for i in range(1,N+1): # 물건 종류
        for j in range(1,K+1): # 무게 한도
            if  data[i-1][0]<=j:
                    sum[j][i]=max(sum[j][i-1], sum[j-data[i-1][0]][i-1]+data[i-1][1])
            elif data[i-1][0]>j:
                    sum[j][i]=sum[j][i-1]

    print(max(sum[K]))

Sol()