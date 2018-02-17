import sys
N=input()
blank=[" "]*N
star=["*"]*((N<<1)+1)
for i in xrange(N):
    print "".join(blank[(i+1):]+star[:(i<<1)+1])