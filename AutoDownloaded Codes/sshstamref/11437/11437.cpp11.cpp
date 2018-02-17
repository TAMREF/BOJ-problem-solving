#include <bits/stdc++.h>
using namespace std;
const int MAXN=50005, MAXD=17;
int p[MAXD][MAXN], dep[MAXN];
bool vis[MAXN];
vector<int> link[MAXN];
int N, M;
void dfs(int x, int d){
    vis[x]=true;
    dep[x]=d;
    for(int i=1;1<<i<=d;i++) p[i][x]=p[i-1][p[i-1][x]];
    for(int u : link[x]){
        if(!vis[u]){
            p[0][u]=x;
            dfs(u,d+1);
        }
    }
}
void input(){
    scanf("%d",&N);
    for(int i=1,x,y;i<N;i++){
        scanf("%d%d",&x,&y);
        link[x].push_back(y);
        link[y].push_back(x);
    }
    dfs(1,0);
}
void LCA(){
    for(int x=scanf("%d",&M),y;M--;){
        scanf("%d%d",&x,&y);
        if(dep[x]<dep[y]) swap(x,y);
        for(int a=dep[x]-dep[y],i=0;a;i++){
            if(a&1<<i){
                a-=1<<i;
                x=p[i][x];
            }
        }
        for(int l=MAXD;l&&x!=y;--l)
            if(p[l-1][x]!=p[l-1][y])
                x=p[l-1][x], y=p[l-1][y];
        printf("%d\n",x==y?x:p[0][x]);
    }
}
int main(){
    input();
    LCA();
    return 0;
}
