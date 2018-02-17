for _ in range(int(input())):
    a=list(map(int,input().split()))[1::]
    f=sum(a)/len(a)
    cnt=0
    for i in a:
        if i>f:cnt+=1
    print("%.3f%%"%(cnt/len(a)*100))