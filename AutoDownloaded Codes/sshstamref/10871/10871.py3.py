N, X=map(int,input().split(' '))
t=map(int,input().split(' '))
u=""
for i in t:
    if(i<X): u+=(str(i)+" ")
print(u)
