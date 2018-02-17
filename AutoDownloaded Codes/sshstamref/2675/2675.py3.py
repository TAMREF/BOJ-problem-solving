for i in range(int(input())):
    n, x=input().split(' ')
    S=""
    for i in x: S+=i*int(n)
    print(S)
