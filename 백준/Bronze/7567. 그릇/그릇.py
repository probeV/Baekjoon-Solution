d = input()

sum = 10

for i in range(1,len(d)):
    if d[i-1] == d[i]:
        sum += 5
    else:
        sum += 10

print(sum)