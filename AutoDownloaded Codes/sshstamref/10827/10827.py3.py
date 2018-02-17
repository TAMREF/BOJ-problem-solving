s=input()
if(len(s.split('.'))==2):
    a,b=s.split('.')
    x,y=b.split(' ')
    c=len(x)
    if(a!='0'):
        d=int(a+x)**int(y)
        print(str(d)[:-c*int(y)]+'.'+str(d)[-c*int(y):])
    else:
        d=str(int(x)**int(y))
        while len(d)<c*int(y): d='0'+d
        print("0."+d)
else:
    p,q=map(int,s.split(' '))
    print(p**q)
