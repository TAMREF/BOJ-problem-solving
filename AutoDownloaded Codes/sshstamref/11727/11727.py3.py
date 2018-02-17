F=[1,1]
n=int(input())
for i in range(2,n+1):
    F.append(F[-1]+2*F[-2])
print(F[n]%10007)
