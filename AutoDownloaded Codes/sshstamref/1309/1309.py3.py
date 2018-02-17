N=int(input())
x,y,z=1,0,0
for i in range(N):
    x,y,z=(x+y+z)%9901,(x+z)%9901,(x+y)%9901
print((x+y+z)%9901)