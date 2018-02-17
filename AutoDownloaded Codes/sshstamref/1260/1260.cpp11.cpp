#include <bits/stdc++.h>
using namespace std;
vector<int> G[1005];
bool dv[1005];
void dfs(int x){
    printf("%d ",x);
    dv[x]=true;
    for(int u : G[x]) if(!dv[u]) dfs(u);
}
void bfs(int x){
    puts("");
    int q[1005]={},f=0,r=0;
    fill(dv,dv+1005,false);
    dv[q[r++]=x]=true;
    while(f!=r){
        int c=q[f++];
        printf("%d ",c);
        for(int u : G[c])
            if(!dv[u]){
                q[r++]=u;
                dv[u]=true;
            }
    }
}
int main(){
    int n,m,v;
    for(int a,b=scanf("%d%d%d",&n,&m,&v);m--;){
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=0;i<=n;i++) sort(G[i].begin(),G[i].end());
    dfs(v);
    bfs(v);
}