from collections import deque
import sys
input=sys.stdin.readline

L, C=map(int, input().split())
alphabet=list(input().split())
visited=[False]*C
vowel=['a','e','i','o','u']
result=""

alphabet.sort()

def DFS(x,result):
    for i in range(x,len(alphabet)):
        if len(result)==L and (set(result) & set(vowel)) and len(set(result) - set(vowel))>=2:
            print(result)
            return
        if visited[i]==False:
            visited[i]=True
            DFS(i,result+alphabet[i])
            visited[i]=False

DFS(0,result)
