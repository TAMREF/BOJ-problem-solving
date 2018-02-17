#include <cstdio>
#include <algorithm>
#include <cstdlib>
struct p
{
    int x, y, z, ind;
} tam[100003];
int rep[100003];
inline int dis(p a, p b)
{
    return std::min(abs(a.x-b.x),std::min(abs(a.y-b.y),abs(a.z-b.z)));
}
class ed
{
    public:
    p p1, p2;
    int d;
    void init(p a, p b)
    {
            p1=a;
            p2=b;
            d=dis(a,b);
    }
} r[300009];
bool cmpx(p a, p b)
{
    return a.x<b.x;
}
bool cmpy(p a, p b)
{
    return a.y<b.y;
}
bool cmpz(p a, p b)
{
    return a.z<b.z;
}
bool cmpe(ed a, ed b)
{
    return a.d<b.d;
}
int f(int x)
{
    if(rep[x]==x) return x;
    rep[x]=f(rep[x]);
    return rep[x];
}
void cn(int x, int y)
{
    x=f(x),y=f(y);
    (x<y)?(rep[y]=x):(rep[x]=y);
}
int main()
{
    int N; scanf("%d",&N);
    bool(*cmp[3])(p,p) = {cmpx, cmpy, cmpz};
    for(int i=0;i<N;i++)
    {
        scanf("%d %d %d",&tam[i].x,&tam[i].y,&tam[i].z);
        tam[i].ind=rep[i]=i;
    }
    for(int c=0;c<3;c++)
    {
        std::sort(tam,tam+N,cmp[c]);
        for(int i=0;i<N-1;i++)
            r[c*(N-1)+i].init(tam[i],tam[i+1]);
    }
    std::sort(r,r+3*(N-1),cmpe);
    long long cost=0;
    for(int i=0;i<3*(N-1);i++)
    {
        if(f(r[i].p1.ind)!=f(r[i].p2.ind))
        {
            cn(r[i].p1.ind,r[i].p2.ind);
            cost+=r[i].d;
        }
    }
    printf("%lld\n",cost);
}
