for _ in range(int(input())):
    L=list(map(int,input().split()))
    if L[0]&1:
        print('YES')
        continue
    #print(L[1::2],L[2::2])
    print('YES' if abs(sum(L[1::2])-sum(L[2::2]))<2 else 'NO')