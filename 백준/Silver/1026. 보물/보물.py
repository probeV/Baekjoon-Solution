N=int(input())
result=0

arr1=list(map(int, input().split()))
arr2=list(map(int, input().split()))

arr1.sort()
arr2.sort()
arr2.reverse()

for i in range(len(arr1)):
    result+=arr1[i]*arr2[i]

print(result)