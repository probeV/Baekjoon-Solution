import sys
input=sys.stdin.readline

N=int(input())
row=[0]*N
count=0

def check(x):
    for i in range(x):
        if row[x]==row[i] or abs(row[x]-row[i])==abs(x-i):
            return False
    return True

def n_queen(x):
    global count
    if x==N:
        count+=1
        return
    else:
        for i in range(N):
            row[x]=i
            if check(x):   
                n_queen(x+1)

n_queen(0)
print(count)