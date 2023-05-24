import sys
input=sys.stdin.readline

N = int(input())
p="IOI"
M= int(input())
S=input()

result_p=str(p+"OI"*(N-1))
result=0

for i in range(M-2*(N)+1):
    if S[i]=="I":
        temp=S[i:i+2*N+1]
        if temp==result_p:
            result+=1


print(result)