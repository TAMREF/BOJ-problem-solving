def dsum(x): return sum(list(map(int,str(x))))
d=[True]*10001
cnt=0
for i in range(1,10001):
    k=i+dsum(i)
    if k<10001:
        d[k]=False
for i in range(1,10001):
    if d[i]==True: print(i)