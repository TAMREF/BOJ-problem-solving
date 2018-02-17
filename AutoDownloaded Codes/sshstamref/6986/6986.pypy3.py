n,k=list(map(int,input().split()))
A=[]
x=[]
for i in range(n):
    x=list(map(int,input().split('.')))
    A.append(x[0]*10+x[1])
A.sort()
print("%.2f"%(sum(A[k:n-k:])/(10*(n-2*k))+1e-9))
for i in range(k):
    A[i]=A[k]
    A[-i-1]=A[-k-1]
print("%.2f"%(sum(A)/(10*n)+1e-9))