n=1000-int(input())
money=[500,100,50,10,5,1]
cnt=0
for i in money:
    cnt+=n//i
    n%=i
print(cnt)