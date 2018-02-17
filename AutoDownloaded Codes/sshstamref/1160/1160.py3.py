m,a,c,x0,n,g=list(map(int,input().split()))
op=[[a,c]]
i=0
while 1<<i<=n:
    j=op[-1][0];k=op[-1][1]
    op.append([j*j%m,(j*k%m+k)%m])
    i+=1
b=0
while 1<<b<=n:
    if n&1<<b:
        x0=(op[b][0]*x0%m+op[b][1])%m
    b+=1
print(x0%g)