A,B,C=map(int,input().split())
time=int(input())
A=A+time//3600
B=B+(time%3600)//60
C=C+(time%60)
while C>=60 or B>=60 or A>=24:
    if C>=60:
        C=C-60
        B=B+1
    if B>=60:
        B=B-60
        A=A+1
    if A>=24:
        A=A-24
print(A, B ,C)