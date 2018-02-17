p = 9223372036854775837
inv = [0,1]
invorial = [0,1]
factorial = [1,1]
for i in range(2,100005):
    inv.append((p-p//i)*inv[p%i]%p)
    invorial.append(invorial[i-1]*inv[i]%p)
    factorial.append(factorial[i-1]*i%p)

def comb(n,r):
    r = min(r,n-r)
    if r==0: return 1
    return factorial[n]*invorial[r]*invorial[n-r]%p

def ipow(x,k):
    ret = 1
    po = x
    while k>0:
        if (k&1)==1:
            ret = ret*po%p
        po = po*po%p
        k>>=1
    return ret
for _ in range(int(input())):
    t,x,r,c=list(map(int,input().split()))
    print(t,ipow(x,r-c)*comb(r,c)%p)
