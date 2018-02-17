n=int(input());Q=[0]*n;ans=0
for t in range(n): Q[t]=int(input())
for i in range(20):
    cnt=0
    for j in Q:
        if j&1<<i: cnt+=1
    ans+=cnt*(n-cnt)<<i
print(ans)