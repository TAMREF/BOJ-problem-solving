#include <bits/stdc++.h>
#define cz __builtin_ctz
using namespace std;
typedef long long ll;
typedef pair<int,ll> pil;
const int mx=100005, lg=17;
int p[lg][mx], dep[mx];
ll S[lg][mx];
vector<pil> G[mx];
int V;
void dfs(int x, int d=1){
    dep[x]=d++;
    for(int i=1; 1<<i < d; i++){
        p[i][x]=p[i-1][p[i-1][x]];
        S[i][x]=S[i-1][x]+S[i-1][p[i-1][x]];
    }
    for(pil &u : G[x]){
        if(dep[u.first]) continue;
        p[0][u.first]=x;
        S[0][u.first]=u.second;
        dfs(u.first,d);
    }
}
void init(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>V;
    for(int i=1,a,b,c;i<V;i++){
        cin>>a>>b>>c;
        G[a].push_back({b,(ll)c});
        G[b].push_back({a,(ll)c});
    }
    dfs(1,1);
}
inline int climb(int x, int mask, ll& s){
    for(int j=cz(mask);mask;j=cz(mask)){
            //cout<<"mask = "<<mask<<endl;
        mask ^= 1<<j;
        s+=S[j][x];
        x=p[j][x];
    }
    return x;
}
ll Track(int u, int v, int& lca){
    ll psum=0;
    if(dep[u]<dep[v]) swap(u,v);
    u=climb(u,dep[u]-dep[v],psum);
    for(int i=lg-1;i>=0 && u!=v;--i){
        if(p[i][u]!=p[i][v]){
            psum+= S[i][u] + S[i][v];
            u=p[i][u], v=p[i][v];
        }
    }
    if(u!=v){
        psum+=S[0][u]+S[0][v];
        lca=p[0][u];
    }else{
        lca=u;
    }
    return psum;
}
int kth(int u, int v, int k){
    int l;
    ll g;
    Track(u,v,l);
    //cout<<"lca("<<u<<","<<v<<") = "<<l<<'\n';
    if(dep[u]-dep[l]+1>=k) return climb(u,k-1,g);
    k-=dep[u]-dep[l];
    //cout<<"k="<<k<<endl;
    return climb(v,dep[v]-dep[l]-k+1,g);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    init();
    int Q,a,b,c,d;
    for(cin>>Q;Q--;){
        cin>>a>>b>>c;
        if(a^1){
            cin>>d;
            cout<<kth(b,c,d)<<'\n';
        }else{
            cout<<Track(b,c,d)<<'\n';
            //cout<<"lca("<<b<<","<<c<<") = "<<d<<'\n';
        }
    }
    return 0;
}