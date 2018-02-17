N,r,c=list(map(int,input().split()))
cnt=0
while N>0:
    if r<2**(N-1) and c<2**(N-1): cnt=cnt 
    elif r<2**(N-1) and c>=2**(N-1):
        cnt=cnt+2**(2*N-2)
        c=c-2**(N-1)
    elif r>=2**(N-1) and c<2**(N-1):
        cnt=cnt+2**(2*N-1)
        r=r-2**(N-1)
    else:
        cnt=cnt+3*(2**(2*N-2))
        r=r-2**(N-1)
        c=c-2**(N-1)
    N=N-1
print(cnt)
