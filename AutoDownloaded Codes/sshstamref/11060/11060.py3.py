n=int(input())
a=list(map(int,input().split()))
d=[n+1]*n
d[n-1]=0
for i in range(n-2,-1,-1):
    for j in range(i+1,min(i+a[i]+1,n)):
        d[i]=min(d[i],d[j]+1)
print(-1 if d[0]==n+1 else d[0])