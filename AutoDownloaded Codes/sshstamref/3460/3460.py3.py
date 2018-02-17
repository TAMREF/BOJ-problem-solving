for i in range(int(input())):
    n=int(input())
    Q=[]
    for i in range(25):
        if n&1<<i: Q.append(i)
    print(*Q)
