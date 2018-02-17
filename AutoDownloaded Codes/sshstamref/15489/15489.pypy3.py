C = [[0]*35 for _ in range(35)]

for i in range(35):
    C[i][0] = 1

for i in range(1,35):
    for j in range(1,i+1):
        C[i][j] = C[i-1][j] + C[i-1][j-1]

r,c,w=list(map(int,input().split()))
r -= 1
c -= 1

ans = 0
for i in range(0,w):
    for j in range(0,i+1):
        ans += C[r+i][c+j]

print(ans)
