n,k=list(map(int,input().split()))
vis=[True]*65537
primes=[2]
for i in range(3,65537,2):
    if(vis[i]):
        primes.append(i)
        for j in range(i*i,65537,i):
            vis[j]=False
#print(len(primes))
for _ in range(n):
    x=input();y=list(x);z=int(x)
    flag=True
    for i in range(len(y)-3):
        if y[i]==y[i+1] and y[i]==y[i+2] and y[i]==y[i+3]:
            flag=False
            break
    for p in primes:
        if p>k: break
        if z%p==0:
            flag=False
            break
    if z<=k: 
        flag=False
    print("YES"if flag else "NO")