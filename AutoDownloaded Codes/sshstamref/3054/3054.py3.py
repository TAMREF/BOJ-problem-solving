s=input()
n = len(s); m = 4 * n + 1
a = '..#...#...*.' * (n) + '.'
b = '.#.#.#.#.*.*' * (n) + '.'
c = ''
for k in s:
    c += '#.'+k+'.'
c += '#'
lc = list(c)
for i in range(n):
    if 12 * i + 8 >= m-1: break
    else: lc[12 * i + 8] = '*'
    if 12 * i + 12 >= m: break
    else: lc[12 * i + 12] = '*'
c = ''
for k in lc:
    c += k
print(a[:m],b[:m],c[:m],b[:m],a[:m],sep='\n')