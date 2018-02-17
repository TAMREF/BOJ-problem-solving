from math import ceil
f=lambda:list(map(int,input().split()))
n,m=f()
A=[];B=[]
for _ in range(m):
    a,b=f()
    A.append(a);B.append(b)
A.sort();B.sort()
ans=1000000000
for y in range(int(ceil(n/6)),-1,-1):
    ans=min(ans,A[0]*y+B[0]*max(0,n-6*y))
print(ans)