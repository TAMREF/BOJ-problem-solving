N=int(input())
P=list(map(int,input().split()))
D=[]
E=0
for i in range(N+1):
    E=0
    for j in range(i):
        E=max(E,D[j]+P[i-1-j])
    D.append(E)
print(D[-1])
