k=int(input())

arr=list(input().split())
max, min="",""

used=[0]*10

def check(i,j,k):
    if k=='<':
        return i<j
    else:
        return i>j
    
def solve(idx,s):
    global max, min
    if(idx==k+1):
        if len(min)==0:
            min=s
        else:
            max=s
        return
    for i in range(10):
        if used[i]==0:
            if idx==0 or check(s[-1], str(i), arr[idx-1]):
                used[i]=1
                solve(idx+1,s+str(i))
                used[i]=0

solve(0,"")
print(max)
print(min)