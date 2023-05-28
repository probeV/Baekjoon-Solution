import sys
input=sys.stdin.readline

N=int(input())

weight=[[0]*(N+1)]
visited=[False]*(N+1)
result=[]

for i in range(N):
    inp=list(map(int, input().split()))
    weight.append([0]+inp)


def find(i, count, temp_w,v):

        index=0
        for _ in weight[i]:
            if _:
                if count==N:
                    if weight[i][start]!=0:
                        result.append(temp_w+weight[i][start])
                    return
                if not v[index]:
                    v[index]=True
                    find(index, count+1, temp_w+_,v)
                    v[index]=False
            index+=1



start=1
visited[start], visited[0]=True, True
find(start,1,0,visited)
print(min(result))