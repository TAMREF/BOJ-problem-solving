#include <bits/stdc++.h>
#define va first
#define vb second
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
const int MX=100005;
vector<pii> cutedge;
vector<int> G[MX];
int dt[MX], V, E, t;
inline pii sw(pii p){
    return p.va<p.vb?p:mp(p.vb,p.va);
}
int dfs(int x, int p){
    int ret=dt[x]=++t,f;
    for(int u : G[x]){
        if(!dt[u]){
            f=dfs(u,x);
            if(f>dt[x]) cutedge.push_back(sw({x,u}));
            ret=min(ret,f);
        } else if(u!=p){
            ret=min(ret,dt[u]);
        }
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin>>V>>E;
    for(int a,b;E--;){
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1,0);
    sort(cutedge.begin(),cutedge.end());
    cout<<cutedge.size()<<endl;
    for(pii t : cutedge)
        cout<<t.va<<' '<<t.vb<<'\n';
    return 0;
}
