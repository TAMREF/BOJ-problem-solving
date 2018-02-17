#include <bits/stdc++.h>
using namespace std;
set<int> cutv;
const int MAXV=10005;
int dt[MAXV], numc[MAXV], V, E, t;
vector<int> link[MAXV];
int dfs(int x, int rt){
    int ret=dt[x]=++t, f;
    for(int &u : link[x]){
        if(!dt[u]){
            ++numc[x];
            f=dfs(u,0);
            if(!rt&&f>=dt[x]) cutv.insert(x);
            ret=min(ret,f);
        } else ret=min(ret,dt[u]);
    }
    if(rt&&numc[x]>1) cutv.insert(x);
    return ret;
}
int main(){
    for(int x,y=scanf("%d%d",&V,&E);E--;){
        scanf("%d%d",&x,&y);
        link[x].push_back(y); link[y].push_back(x);
    }
    for(int i=1;i<=V;i++) if(!dt[i]) dfs(i,1);
    printf("%d\n",cutv.size()); for(int u : cutv) printf("%d ",u);
    return 0*puts("");
}
