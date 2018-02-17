#include <bits/stdc++.h>
using namespace std;
const int MAXV=20010;
int scc[MAXV], dt[MAXV];
int g, t;
int V, E;
vector<int> in[MAXV], out[MAXV], ft;
bool vis[MAXV];
void dfs(int x){
    dt[x]=++t;
    for(int u : out[x]){
        if(!dt[u]) dfs(u);
    }
    ft.push_back(x);
}
void dcp(int x){
    scc[x]=g;
    for(int u : in[x]){
        if(!scc[u]) dcp(u);
    }
}
int main(){
    scanf("%d%d",&V,&E);
    for(int x,y,nx,ny;E--;){
        scanf("%d%d",&x,&y);
        out[V-x].push_back(V+y);
        in[V+y].push_back(V-x);
        out[V-y].push_back(V+x);
        in[V+x].push_back(V-y);
    }
    for(int i=1;i<=V;i++){
        if(!dt[V+i]) dfs(V+i);
        if(!dt[V-i]) dfs(V-i);
    }
    for(int i=ft.size();i;i--){
        if(!scc[ft[i-1]]){
            ++g;
            dcp(ft[i-1]);
        }
    }
    for(int i=1;i<=V;i++){
        if(scc[V+i]==scc[V-i]) return 0*puts("0");
    }
    return 0*puts("1");
}
