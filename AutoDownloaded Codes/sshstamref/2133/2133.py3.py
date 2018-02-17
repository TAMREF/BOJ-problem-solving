n=int(input())
if n&1: print(0)
elif n<5: print(4*n-5)
else:
    a,b,c=[3,11,0]
    for _ in range(n//2-2):
        c=4*b-a;a=b;b=c;
    print(c)
