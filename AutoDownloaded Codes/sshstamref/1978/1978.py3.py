from math import sqrt
def isprime(x):
    if x==1: return False
    for i in range(2,1+int(sqrt(x))):
        if x%i==0: return False
    return True
n=0*int(input())
for j in list(map(int,input().split())):
    if isprime(j): n+=1
print(n)
