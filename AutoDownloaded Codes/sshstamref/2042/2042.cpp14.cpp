#include <cstdio>
using namespace std;
long long segtree[4444444], a[1111111];
long long make_tree(long long node, long long s, long long e)
{
    if(s==e) return segtree[node]=a[s];
    return segtree[node]=make_tree(2*node,s,(s+e)/2)+make_tree(2*node+1,(s+e)/2+1,e);
}
long long getsum(long long node, long long s, long long e, long long l, long long r)
{
    if(l>e|| s>r) return 0;
    if(s>=l && e<=r) return segtree[node];
    return getsum(2*node,s,(s+e)/2,l,r)+getsum(2*node+1,(s+e)/2+1,e,l,r);
}
void update(long long node, long long s, long long e, long long i, long long d)
{
    if(i<s||i>e) return;
    segtree[node]=segtree[node]+d-a[i];
    if(s!=e) {update(node*2,s,(s+e)/2,i,d); update(node*2+1,(s+e)/2+1,e,i,d);}
}
int N, M, K, p, b, c;
int main()
{
    scanf("%d%d%d",&N,&M,&K);
    for(int i=1;i<=N;i++) scanf("%d",&a[i]);
    make_tree(1,1,N);
    for(int i=0;i<M+K;i++)
    {
        scanf("%d%d%d",&p,&b,&c);
        if(p==2) printf("%lld\n",getsum(1,1,N,b,c));
        else {update(1,1,N,b,c); a[b]=c;}
    }
}
