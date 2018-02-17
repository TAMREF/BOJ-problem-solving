#include <bits/stdc++.h>
using namespace std;
const int mx=32005;
vector<int> G[mx];
int V, E, vis[mx], topo[mx], g;
void dfs(int x){
    vis[x]=1;
    for(int u : G[x]){
        if(!vis[u]){
            dfs(u);
        }
    }
    topo[g++]=x;
}
int main(){
    for(int a,b=scanf("%d %d",&V,&E);E--;){
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
    }
    for(int i=1;i<=V;i++) if(!vis[i]) dfs(i);
    for(int i=V-1;i>=0;i--) printf("%d ",topo[i]);
    return 0;
}