#include <bits/stdc++.h>
using namespace std;
const int MX = 105;
int N, M, i, j, k, x, y, idx_dfs, idx_fin, num_scc;
int scc[MX], d[MX], f[MX], cost[MX], mico[MX];
vector<int> ding[MX], in[MX], out[MX];
void input(){
    scanf("%d",&N);
    fill(mico,mico+N+1,INT_MAX);
    for(i=1;i<=N;i++){
        in[i].clear();
        out[i].clear();
    }
    for(int i=1;i<=N;i++) scanf("%d",&cost[i]);
    for(int i=1, x;i<=N;i++){
        for(int j=1;j<=N;j++){
            scanf("%1d",&x);
            if(x){
                out[i].push_back(j);
                in[j].push_back(i);
            }
        }
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
    mico[scc[p]] = min(mico[scc[p]], cost[p]);
    for(int &u : in[p]){
        if(!scc[u]){
            scc[u]=scc[p];
            dfs_r(u);
        }
    }
}

int main(){
    input();
    for(i=1;i<=N;i++) if(!d[i]) dfs_f(i);
    for(i=N;i>0;i--) if(!scc[f[i]]) dfs_r(f[i]);
    long long C = 0;
    for(int i=1;i<=num_scc;i++) C += mico[i];
    printf("%d\n",C);
}
