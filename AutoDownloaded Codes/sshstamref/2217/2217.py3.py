def mx(i,j):
    if i<j : return j
    else: return i
N=int(input())
M=0
a=[]
for i in range(int(N)): a.append(int(input()))
a.sort()
for i in range(int(N)): M=mx(M,(N-i)*a[i])
print(M)
