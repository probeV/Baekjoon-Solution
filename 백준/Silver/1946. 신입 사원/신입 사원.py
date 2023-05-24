import sys
T=int(sys.stdin.readline())

for _ in range(T):
    N=int(sys.stdin.readline())
    rank=[]
    result=1
    for i in range(N): 
        temp=list(map(int, sys.stdin.readline().split()))
        rank.append(temp)
    rank=sorted(rank)

    temp=rank[0][1]
    for i in range(1,N):
        if temp>rank[i][1]:
            result+=1
            temp=rank[i][1]

    print(result)