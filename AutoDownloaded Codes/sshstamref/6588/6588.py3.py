import sys
p=[True]*1000000
primes=[]
for i in range(3,1000000,2):
    if p[i]==True:
        primes.append(i)
        for j in range(i*i,1000000,i):
            p[j]=False
while True:
    x=int(input())
    if x==0: sys.exit()
    for i in primes:
        if p[x-i]==True:
            print("%d = %d + %d"%(x,i,x-i))
            break