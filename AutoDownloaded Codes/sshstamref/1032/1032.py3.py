N=int(input())
a=[]
b=""
flag=False
for i in range(N):
    a.append(input())
for k in range(len(a[0])):
    for j in range(1,N):
        if(a[j][k]!=a[0][k]): flag=True
    if flag: b+='?'
    else: b+=a[0][k]
    flag=False
print(b)