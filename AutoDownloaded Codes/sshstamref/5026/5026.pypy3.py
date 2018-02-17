for _ in range(int(input())):
    L = input().split('+')
    print('skipped' if len(L)<2 else int(L[0])+int(L[1]))
