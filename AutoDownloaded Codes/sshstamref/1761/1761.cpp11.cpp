#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;
typedef pair<int,int> pii;
const int MAXD=16, MAXN=40005;
int p[MAXD][MAXN], dis[MAXD][MAXN], dep[MAXN];
int N, M;
bool vis[MAXN];
vector<pii> link[MAXN];
void dfs(int x, int d){
    vis[x]=true;
    dep[x]=d;
    for(int i=1;(1<<i)<=d;i++){
        p[i][x]=p[i-1][p[i-1][x]];
        dis[i][x]=dis[i-1][x]+dis[i-1][p[i-1][x]];
    }
    for(pii u : link[x]){
        if(!vis[u.fst]){
            dis[0][u.fst]=u.snd;
            p[0][u.fst]=x;
            dfs(u.fst,d+1);
        }
    }
}
void input(){
    for(int i=1,x=scanf("%d",&N),y,z;i<N;i++){
        scanf("%d%d%d",&x,&y,&z);
        link[x].push_back({y,z});
        link[y].push_back({x,z});
    }
    dfs(1,0);
}
void query(){
    for(int x=scanf("%d",&M), y, ans;M--;){
        ans=0; scanf("%d%d",&x,&y);
        if(dep[x]<dep[y]) swap(x,y);
        for(int d=dep[x]-dep[y],i=0;d;++i){
            if(d&1<<i){
                d-=(1<<i);
                ans+=dis[i][x];
                x=p[i][x];
            }
        }
        for(int l=MAXD;l&&x!=y;--l){
            if(p[l-1][x]!=p[l-1][y]){
                ans+=dis[l-1][x]+dis[l-1][y];
                x=p[l-1][x], y=p[l-1][y];
            }
        }
        printf("%d\n",ans+(x==y?0:dis[0][x]+dis[0][y]));
    }
}
int main(){
    input();
    query();
    return 0;
}
