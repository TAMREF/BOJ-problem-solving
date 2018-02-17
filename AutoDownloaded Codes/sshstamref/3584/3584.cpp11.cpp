#include <bits/stdc++.h>
using namespace std;
const int mx=10005, lg=16;
int p[lg][mx], dt[mx];
vector<int> C[mx];
int t,n,x,y,rt;
void input(){
    memset(p,0,sizeof(p));
    memset(dt,0,sizeof(dt));
    for(int i=0;i<mx;i++) C[i].clear();
    cin>>n;
    for(int i=1,a,b;i<n;i++){
        cin>>a>>b;
        p[0][b]=a;
        C[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(!p[0][i]){
            rt=i; break;
        }
    }
    cin>>x>>y;
}
void dfs(int w, int de){
    dt[w]=++de;
    for(int d=1;1<<d<=n;++d) p[d][w]=p[d-1][p[d-1][w]];
    for(int u : C[w]) dfs(u,de);
}
int lca(int g, int h){
    if(dt[g]<dt[h]) swap(g,h);
    int dd=dt[g]-dt[h];
    for(int b=lg-1;b>=0;b--){
        if(dd&1<<b){
            g=p[b][g];
        }
    }
    for(int b=lg-1;b>=0;b--){
        if(p[b][g]!=p[b][h]) g=p[b][g], h=p[b][h];
    }
    return g==h?g:p[0][g];
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    for(cin>>t;t--;){
        input();
        dfs(rt,0);
        printf("%d\n",lca(x,y));
    }
}