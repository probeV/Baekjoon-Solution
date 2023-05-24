from itertools import permutations

n = int(input())
arr = list(map(int ,input().split()))

per = list(permutations(arr, n))
def calculator(temp):
  total = 0
  for i in range(len(temp)-1):
    total += abs(temp[i]-temp[i+1])
  return total

answer = 0
for temp in per:
  answer = max(answer, calculator(temp))

print(answer)