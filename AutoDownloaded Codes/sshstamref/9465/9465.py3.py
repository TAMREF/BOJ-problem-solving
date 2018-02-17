for t in range(int(input())):
    N=int(input())
    U=list(map(int,input().split()))
    D=list(map(int,input().split()))
    A,B,C=[[0]*N for _ in range(3)]
    A[0]=U[0]; B[0]=D[0];
    for i in range(1,N):
        A[i]=max(B[i-1],C[i-1])+U[i]
        B[i]=max(A[i-1],C[i-1])+D[i]
        C[i]=max(A[i-1],B[i-1])
    print(max(A[N-1],B[N-1],C[N-1]))
    
