num=int(input())
for i in range(2,num+1):
    while num%i==0:
        print(i)
        num=num/i
    if num==1:
        break