n=int(input())
b=[]
dp=[[0]*(n+10) for _ in range(n+10)]
for _ in range(n):
    b.append(list(map(int,input().split())))
dp[n-1][n-1]=1
for i in range(n-1,-1,-1):
    for j in range(n-1,-1,-1):
        if i==n-1 and j==n-1: continue
        dp[i][j]=dp[i+b[i][j]][j]+dp[i][j+b[i][j]]
print(dp[0][0])