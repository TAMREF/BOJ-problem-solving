#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int a[100005], N, M,x, y;
pii seg[300015], kan;
pii B(int node, int s, int e)
{
    if(s==e) return seg[node]={a[s],a[s]};
    pii G = B(2*node,s,(s+e)/2), H = B(2*node+1,(s+e)/2+1,e);
    return seg[node]={min(G.first,H.first),max(G.second,H.second)};
}
pii gm(int node, int s, int e, int l, int r)
{
    if(e<l || r<s) return {2e9,0};
    if(l<=s && e<=r) return seg[node];
    pii Z = gm(2*node,s,(s+e)/2,l,r), W = gm(2*node+1,(s+e)/2+1,e,l,r);
    return {min(Z.first,W.first),max(Z.second,W.second)};
}
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++) scanf("%d",&a[i]);
    B(1,1,N);
    for(;M--;){
        scanf("%d %d",&x,&y);
        kan = gm(1,1,N,x,y);
        printf("%d %d\n",kan.first,kan.second);
    }
    return 0;
}
