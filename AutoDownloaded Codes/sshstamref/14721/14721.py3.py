n = int(input())
X = []
Y = []
for i in range(n):
    x,y = list(map(int,input().split()))
    X.append(x)
    Y.append(y)

rm = 1000000000000000000;  ra = -1; rb = -1
for a in range(1,101):
    for b in range(1,101):
        rss = 0
        for i in range(n):
            rss += (Y[i] - a * X[i] - b)**2
        if rm > rss:
            rm = rss
            ra = a
            rb = b

print(ra,rb)