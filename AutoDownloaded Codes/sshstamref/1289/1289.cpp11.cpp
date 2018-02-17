#include <bits/stdc++.h>
#define va first
#define vb second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MX=100005, MOD=1000000007;
vector<pii> G[MX];
bool vis[MX];
ll ans;
inline ll p(ll u, ll v){return (u+v)%MOD;}
ll dfs(int x){
    vis[x]=true;
    ll S=0,P=0,b=0;
    for(pii u : G[x]){
        if(vis[u.va]) continue;
        b=1LL*u.vb*(dfs(u.va)+1)%MOD;
        S=p(S,b), P=p(P,b*b%MOD);
    }
    ans=p(ans,p(S,500000004LL*p(S*S%MOD,p(MOD,-P%MOD))%MOD));
    return S;
}
int main(){
    int V; scanf("%d",&V);
    for(int i=1,a,b,w;i<V;i++){
        scanf("%d%d%d",&a,&b,&w);
        G[a].pb(mp(b,w));
        G[b].pb(mp(a,w));
    } dfs(1);
    printf("%lld\n",ans);
}
