a=int(input())
x=1 #end with 1
y=0 #end with 0
z=0
w=0
for i in range(a-1):
    z=y
    y+=x
    x=z
print(x+y)
    