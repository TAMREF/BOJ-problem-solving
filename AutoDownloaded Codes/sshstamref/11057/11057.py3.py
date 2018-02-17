n=int(input())
a,b=[[1]*10 for _ in range(2)]
for _ in range(n-1):
    for i in range(10):
        for j in a[:i]:
            b[i]+=j
    a=list(b)
print(sum(a)%10007)
