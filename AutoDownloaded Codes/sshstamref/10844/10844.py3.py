D=[]; D.append([0])
for i in range(1,10): D.append([1])
n=int(input())
tam=0
for i in range(1,n):
    for j in range(10):
        tam=0
        if j>0: tam+=D[j-1][i-1]
        if j<9: tam+=D[j+1][i-1]
        D[j].append(tam%1000000000)
a=0
for j in range(10):
    a+=D[j][-1]
print(a%1000000000)
