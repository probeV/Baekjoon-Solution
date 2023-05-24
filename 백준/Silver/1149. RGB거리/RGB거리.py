import sys
input=sys.stdin.readline

N=int(input())
result=[[0,0,0] for _ in range(N+1)]

for i in range(N):
    weight=list(map(int, input().split()))
    result[i+1][0]=min(result[i][1], result[i][2])+weight[0]
    result[i+1][1]=min(result[i][0], result[i][2])+weight[1]
    result[i+1][2]=min(result[i][0], result[i][1])+weight[2]

print(min(result[N]))