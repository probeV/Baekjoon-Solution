import sys
input=sys.stdin.readline

N,K=map(int, input().split())

def z():
    Bool=[True]*(N+1)
    result=0
    count=0
    for i in range(2,N+1):
        if Bool[i]==True:
            result=i
            count+=1
            if count==K:
                return result
        else:
            continue
        
        j=2
        while i*j<=N:
            if Bool[i*j]==False:
                j+=1
                continue
            Bool[i*j]=False
            result=i*j
            count+=1
            if count==K:
                return result
            j+=1

print(z())