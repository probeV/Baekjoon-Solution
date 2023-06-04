x = int(input())
n = int(input())
sum = 0
for i in range(1,n+1):
    A,B= map(int,input().split())
    sum += A*B
if x == sum:
    print("Yes")
else:
    print("No")