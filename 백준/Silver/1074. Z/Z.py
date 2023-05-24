import sys
input=sys.stdin.readline

N, r, c = map(int, input().split())
result=0

while N!=0:
    N-=1
    if r< pow(2,N) and c<pow(2,N):
        result+=0
    elif r< pow(2,N) and c>=pow(2,N):
        result+=pow(2,N)*pow(2,N)*1
        c-=pow(2,N)
    elif r>= pow(2,N) and c<pow(2,N):
        result+=pow(2,N)*pow(2,N)*2
        r-=pow(2,N)
    elif r>= pow(2,N) and c>=pow(2,N):
        result+=pow(2,N)*pow(2,N)*3
        c-=pow(2,N)
        r-=pow(2,N)
print(result)