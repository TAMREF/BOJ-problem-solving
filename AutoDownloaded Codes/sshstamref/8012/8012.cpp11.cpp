#include <bits/stdc++.h>
using namespace std;
const int mx = 30005, lg = 15;
int p[lg][mx], dep[mx], vis[mx];
vector<int> G[mx];
void dfs(int x, int d){
    vis[x] = 1;
    dep[x] = d;
    for(int i=1;1<<i <= d;++i) p[i][x] = p[i-1][p[i-1][x]];
    for(int &u : G[x]){
        if(!vis[u]){
            p[0][u] = x;
            dfs(u,d+1);
        }
    }
}
int lca(int x, int y){
    if(dep[x]<dep[y]) swap(x,y);
    int di = dep[x]-dep[y];
    for(int i=0;di;++i){
        if(di & 1<<i){
            di ^= (1<<i);
            x = p[i][x];
        }
    }
    for(int i=lg-1;i>=0 && x!=y;i--){
        if(p[i][x] != p[i][y]){
            x = p[i][x]; y = p[i][y];
        }
    }
    return x==y?x:p[0][x];
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,a,b,c=0; cin>>n;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1,0);
    b=1;
    for(cin>>m;m--;){
        cin>>a;
        c+= dep[a]+dep[b]-2*dep[lca(a,b)];
        b=a;
    }
    cout<<c<<endl;
}