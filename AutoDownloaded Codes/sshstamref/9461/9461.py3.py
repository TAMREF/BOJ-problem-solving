P=[1,1,1,2,2]
for i in range(5,101):
    P.append(P[i-1]+P[i-5])
for i in range(int(input())):
    N=int(input())
    print(P[N-1])
