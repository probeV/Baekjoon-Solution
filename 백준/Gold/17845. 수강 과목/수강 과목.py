import sys
input=sys.stdin.readline
def sol():
    N,K=map(int, input().split())
    data=[]
    for _ in range(K):
        v,t=map(int, input().split())
        data.append([t,v])

    sum=[[0]*(K+1) for i in range(N+1)]

    for i in range(1,K+1):   # 과목 수
        for j in range(1,N+1):   # 시간 한도
            if data[i-1][0] <= j:   # 시간 한도가 더 크면
                sum[j][i]=max(sum[j][i-1], sum[j-data[i-1][0]][i-1]+data[i-1][1])  
                # 앞에 있던거 vs 새로 추가할 시간만큼 앞에 넣었던거에서 빼고 새로 추가
            else: #data[i-1][0] > j   # 시간 한도가 더 작으면
                sum[j][i]=sum[j][i-1]   # 앞에 넣어 뒀던거 그대로 가져오기

    print(max(sum[N]))

sol()