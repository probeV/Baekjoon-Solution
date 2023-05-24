import sys

N, K=map(int, sys.stdin.readline().split())
buybottle=0
X=[]
temp=N

while(temp!=0):
    i=0
    while(2**i<=temp):
        i=i+1
    if(i!=0):
        i=i-1
    temp=temp-(2**i)
    X.append(2**i)

while(len(X)>K):
    temp=X.pop()
    buybottle=temp+buybottle
    while(temp*2 in X):
        X.pop()
        temp=temp*2
    X.append(temp*2)
print(buybottle)