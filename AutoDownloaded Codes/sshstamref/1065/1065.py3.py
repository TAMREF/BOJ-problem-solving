n=int(input())
if n<100:
    print(n)
    exit()
cnt=99
for i in range(111,n+1):
    s=list(map(int,str(i)))
    if 2*s[1]==(s[0]+s[2]): cnt+=1
print(cnt)