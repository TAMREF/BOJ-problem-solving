N, K=input().split(' ')
a=[]
L=int(K)
S=0
for i in range(int(N)): a.append(int(input()))
for i in range(int(N)):
    S+=L//a[-i-1]
    L%=a[-i-1]
print(S)
