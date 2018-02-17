a=set()
b=0
for c in input():
    if c==' ':
        if not a.__contains__(b):
            a.add(b)
            print(b,end=' ')
        b=-1
        continue
    else:
        if b==-1: b=0
        b=10*b+int(c)
if b!=-1 and not a.__contains__(b):
    print(b)