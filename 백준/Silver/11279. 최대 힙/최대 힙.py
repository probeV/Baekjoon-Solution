import heapq
import sys

N=int(sys.stdin.readline())

heap=[]

for i in range(N):
    x=int(sys.stdin.readline())
    if x==0:
        if heap:
            a=heapq.heappop(heap)
            print(a[1])
        else:
            print(0)
    else:
        heapq.heappush(heap, (-x, x))
