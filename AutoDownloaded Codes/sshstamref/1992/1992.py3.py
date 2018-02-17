a=[]
def pt(s,e, sd, ed):
    if e==s: return a[s][sd]
    x=pt(s,(s+e)//2, sd, (sd+ed)//2)
    y=pt((s+e)//2+1, e, sd, (sd+ed)//2)
    z=pt(s, (s+e)//2, (sd+ed)//2+1, ed)
    w=pt((s+e)//2+1, e, (sd+ed)//2+1, ed)
    if x==y and y==z and z==w and len(x)==1: return x
    return '('+x+z+y+w+')'
N=int(input())
for i in range(N): a.append(input())
print(pt(0,N-1,0,N-1))    
