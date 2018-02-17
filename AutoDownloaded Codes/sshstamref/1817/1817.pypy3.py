import sys
n,m=list(map(int,input().split()))
if n==0:
    print(0)
    sys.exit(0)
A=list(map(int,input().split()))
box=1;now=0
for i in A:
    if now+i>m:
        box+=1
        now=i
    else:
        now+=i
print(box if now else box-1)