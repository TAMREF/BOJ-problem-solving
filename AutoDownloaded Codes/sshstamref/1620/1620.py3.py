n,q=list(map(int,input().split()))
D={}
for i in range(n):
    S=input()
    D[str(i+1)]=S
    D[S]=str(i+1)
for i in range(q):
    print(D[input()])
