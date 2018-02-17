exec('for _ in range(int(input())):\n\tL = input().split(\'+\')\n\tprint(\'skipped\' if len(L)<2 else int(L[0])+int(L[1]))')
