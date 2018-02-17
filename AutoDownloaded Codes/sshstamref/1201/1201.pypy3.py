n,m,k=list(map(int,input().split()))
S=[]
if m+k>n+1 or m*k<n: print(-1)
else:
    for i in range(n-m+1,n+1):
        S.append(i)
    if k==2:
        for i in range(1,n-m+1): S.append(i)
    else:
        cnt=0; now=k-1
        while cnt<n-m:
            S.append(now)
            if now%(k-1)==1: now=min(n-2,now+2*k-3)
            else: now-=1
            cnt+=1
    print(*S)