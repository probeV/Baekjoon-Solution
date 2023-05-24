import sys
input=sys.stdin.readline

N=int(input())
arr=[]

for _ in range(N):
    arr.append(list(map(int, input().split())))

arr=sorted(arr)

finishmin=arr[0][1]
time=arr[0][1]-arr[0][0]

result=1


for i in range(1,N):
    if time > arr[i][1]-arr[i][0] and finishmin > arr[i][1]:
        time=arr[i][1]-arr[i][0]
        finishmin=arr[i][1]
    elif finishmin <= arr[i][0]:
        result+=1
        time=arr[i][1]-arr[i][0]
        finishmin=arr[i][1]

print(result)