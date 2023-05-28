import sys

def recursion(s, l, r, result):
    if l >= r: return 1, result
    elif s[l] != s[r]: return 0, result
    else: 
        result=result+1
        return recursion(s, l+1, r-1, result)

def isPalindrome(s, result):
    return recursion(s, 0, len(s)-1, result)

T=int(sys.stdin.readline().strip())
for _ in range(T):
    result=1
    case=sys.stdin.readline().strip()
    X,Y=isPalindrome(case, result)
    print(X, Y)