#include <bits/stdc++.h>
using namespace std;
const int MX = 10005;
int N, M, i, j, k, x, y, idx_dfs, idx_fin, num_scc;
int scc[MX], d[MX], f[MX];
vector<int> ding[MX], in[MX], out[MX];
void input(){
    scanf("%d%d",&N,&M);
    for(i=1;i<=N;i++){
        in[i].clear();
        out[i].clear();
    }
    for(i=0;i<M;i++){
        scanf("%d%d",&x,&y);
        out[x].push_back(y);
        in[y].push_back(x);
    }
}
void dfs_f(int p){
    d[p]=++idx_dfs;
    for(int &u : out[p]){
        if(!d[u]) dfs_f(u);
    }
    f[++idx_fin]=p;
}
void dfs_r(int p){
    if(!scc[p]) scc[p]=++num_scc;
    for(int &u : in[p]){
        if(!scc[u]){
            scc[u]=scc[p];
            dfs_r(u);
        }
    }
}
void tame(){
    printf("%d\n",num_scc);
    for(i=1;i<=N;i++) ding[scc[i]].push_back(i);
    for(i=1;i<=num_scc;i++) sort(ding[i].begin(),ding[i].end());
    vector<pair<int,int> > ans={};
    for(i=1;i<=num_scc;i++) ans.push_back(make_pair(ding[i][0],i));
    sort(ans.begin(),ans.end());
    for(auto &u : ans){
        for(auto &v : ding[u.second]) printf("%d ",v);
        puts("-1");
    }
}
int main(){
    input();
    for(i=1;i<=N;i++) if(!d[i]) dfs_f(i);
    for(i=N;i>0;i--) if(!scc[f[i]]) dfs_r(f[i]);
    tame();
}
