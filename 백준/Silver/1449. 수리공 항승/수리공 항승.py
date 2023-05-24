N, L=map(int, input().split())
result, length=1, 0
hole=list(map(int, input().split()))
hole=sorted(hole)
dist=[]

for i in range(0,len(hole)-1):
     dist.append(hole[i+1]-hole[i])

for i in range(len(dist)):
    length+=dist[i]
    if length > L-1:
        result+=1
        length=0
    else:
        pass

print(result)