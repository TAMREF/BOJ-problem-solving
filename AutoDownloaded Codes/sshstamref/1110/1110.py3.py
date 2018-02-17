import sys
n=int(input())
if n==0:
    print(1)
    sys.exit()
m=n; cyc=0
while True:
    if m<10: m*=11
    else: m=(m%10)*10+(m//10+m%10)%10
    cyc=cyc+1
    if m==n: break
print(cyc)