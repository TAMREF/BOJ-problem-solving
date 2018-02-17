n=int(input())
f=[1,1,2]
if n<3: print(f[n])
else:
    for i in range(3,n+1):
        f.append((f[-1]+f[-2])%10007)
    print(f[n]%10007)