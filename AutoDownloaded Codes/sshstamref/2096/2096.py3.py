n=int(input())
m1,m2=[[0]*3 for i in range(2)]
for i in range(n):
    L1=list(map(int,input().split()))
    L2=L1[::]
    L1[0]+=max(m1[:2]); L2[0]+=min(m2[:2])
    L1[1]+=max(m1); L2[1]+=min(m2)
    L1[2]+=max(m1[1:]); L2[2]+=min(m2[1:])
    m1=L1[::]; m2=L2[::]
print(max(m1),min(m2))