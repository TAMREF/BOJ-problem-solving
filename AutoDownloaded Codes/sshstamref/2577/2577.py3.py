f=lambda:int(input())
cnt=[0]*10
for x in str(f()*f()*f()):
    cnt[int(x)]+=1
for i in range(10):
    print(cnt[i])
