n,k=list(map(int,input().split()))
C=[10005]*(k+1)
C[0]=0
for _ in range(n):
    t=int(input())
    for i in range(k+1-t):
        C[i+t]=min(C[i+t],C[i]+1)
print(-1 if C[k]==10005 else C[k])
