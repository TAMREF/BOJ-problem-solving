#include <cstdio>
#include <vector>
#include <algorithm>
std::vector<std::pair<int, std::pair<int, int> > > edge;
int rep[1003];
int f(int x)
{
    if(rep[x]==x) return x;
    rep[x]=f(rep[x]);
    return rep[x];
}
void cn(int x, int y)
{
    x=f(x), y=f(y);
    (x<y)?(rep[y]=x):(rep[x]=y);
}
int main()
{
    int N, M, a, b, c, cnt=0;
    long long T=0;
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++) rep[i]=i;
    for(int i=0;i<M;i++)
    {
        scanf("%d %d %d",&a, &b, &c);
        edge.push_back({c,{a,b}});
    }
    std::sort(edge.begin(),edge.end());
    //printf("%d\n",edge.size());
    for(auto &t : edge)
    {
        if(f(t.second.first)!=f(t.second.second)){
                cn(t.second.first,t.second.second);
                T+=t.first;
        }
    }
    printf("%lld\n",T);
    return 0;
}