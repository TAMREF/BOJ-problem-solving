f=lambda:list(map(int,input().split()))
n,m=f()
Q=[]
for _ in range(n):
    Q.append(f())
for i in range(n):
    for j in range(m):
        Q[i][j]+=max(Q[i-1][j] if i else 0,Q[i][j-1] if j else 0,Q[i-1][j-1] if i and j else 0)
print(Q[n-1][m-1])
