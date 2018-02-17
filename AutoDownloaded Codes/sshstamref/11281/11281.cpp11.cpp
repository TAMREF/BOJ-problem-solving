#include <bits/stdc++.h>
using namespace std;
const int MX=20010;
bool vis[MX];
int N, M, g, scc[MX];
vector<int> f, out[MX], in[MX];
void dfs(int x){
    vis[x]=true;
    for(int u : out[x]) if(!vis[u]) dfs(u);
    f.push_back(x);
}
void dcp(int x){
    scc[x]=g;
    for(int u : in[x]) if(!scc[u]) dcp(u);
}
int main(){
    for(int x,y=scanf("%d%d",&N,&M);M--;){
        scanf("%d%d",&x,&y);
        out[N-x].push_back(N+y);
        out[N-y].push_back(N+x);
        in[N+x].push_back(N-y);
        in[N+y].push_back(N-x);
    }
    for(int i=1;i<=N;i++) if(!vis[N+i]) dfs(N+i);
    for(int i=1;i<=N;i++) if(!vis[N-i]) dfs(N-i);
    for(int i=f.size();i;i--){
        if(!scc[f[i-1]]) dcp(f[i-1]+0*(++g));
    }
    for(int i=1;i<=N;i++) if(scc[N+i]==scc[N-i]) return 0*puts("0");
    puts("1"); for(int i=1;i<=N;i++) printf("%d ",scc[N+i]>scc[N-i]);
}
