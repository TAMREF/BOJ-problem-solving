#include <bits/stdc++.h>
using namespace std;

int dt[2005], scc[2005], vis[2005], t, g, V, E;
vector<int> I[2005], O[2005], ft;

void dfs(int x){
    dt[x] = ++t;
    for(int &u : O[x]){
        if(!dt[u]) dfs(u);
    }
    ft.push_back(x);
}

void dcp(int x){
    scc[x] = g;
    for(int &u : I[x]){
        if(!scc[u]) dcp(u);
    }
}

bool reach(int x, int tg){
    if(scc[x] == scc[tg]) return true;
    vis[x] = 1;
    for(int &u : O[x]){
        if(!vis[u] && reach(u,tg)) return true;
    }
    return false;
}

void init(){
    ft.clear();
    memset(dt,0,sizeof(dt));
    memset(scc,0,sizeof(scc));
    memset(vis,0,sizeof(vis));
    t = g = 0;
    for(int i=0;i<=V+V;i++){
        I[i].clear();
        O[i].clear();
    }

    if(scanf("%d %d",&V,&E)!=2) exit(0);
    for(int X,Y;E--;){
        scanf("%d %d",&X,&Y);

        O[V-X].push_back(V+Y);
        I[V+Y].push_back(V-X);

        O[V-Y].push_back(V+X);
        I[V+X].push_back(V-Y);
    }
}

void sat2(){
    for(int i=1;i<=V;i++){
        if(!dt[V+i]) dfs(V+i);
        if(!dt[V-i]) dfs(V-i);
    }
    for(int i=ft.size();i--;){
        if(!scc[ft[i]]){
            ++g;
            dcp(ft[i]);
        }
    }
    for(int i=1;i<=V;i++){
        if(scc[V+i]==scc[V-i]){
            puts("no");
            return;
        }
    }
    puts( reach(V+1,V-1)?"no":"yes" );
}

int main(){
    ft.reserve(2005);
    while(1){
        init();
        sat2();
    }
}
