import sys
input=sys.stdin.readline

def BinarySearch():
    start,mid,end=0,n//2,n-1
    while True:
        if start > end:
            return False

        if rego[mid] > find:
            end=mid-1
            mid=(start+end)//2
        elif rego[mid]==find:
            return mid
        elif rego[mid] < find:
            start=mid+1
            mid=(start+end)//2

while True:
    try:
        x=int(input())*10000000
        n=int(input())
        rego=[]

        for _ in range(n):
            rego.append(int(input()))

        rego=sorted(rego)

        ans = [-1000000001, -1000000001]
 
        i, j = 0, n-1
        while i < j:
            if rego[i] + rego[j] == x:
                ans = rego[i], rego[j]
                break
            elif rego[i] + rego[j] > x:
                j -= 1
            else:
                i += 1
 
        if ans == [-1000000001, -1000000001]:
            print("danger")
        else:
            print("yes", ans[0], ans[1])
             
    except:
        break