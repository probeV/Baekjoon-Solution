from sys import stdin

n,m = map(int, stdin.readline().split())

k = n//m

a = n%m

print(k)

print(a)