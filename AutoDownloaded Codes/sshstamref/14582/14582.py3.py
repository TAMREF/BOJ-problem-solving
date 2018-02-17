import sys
A=list(map(int,input().split()))
B=list(map(int,input().split()))
C=[]
for i in range(9):
    C.append(A[i])
    C.append(-B[i])
for i in range(18):
    if sum(C[:i:])>0:
        print('Yes')
        sys.exit(0)
print('No')
