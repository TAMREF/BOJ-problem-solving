#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;
typedef pair<int,int> pii;
const int MAXD=18, MAXN=100005, INF=1<<20;
int N, Q;
int p[MAXD][MAXN], m[MAXD][MAXN], M[MAXD][MAXN], dep[MAXN];
bool vis[MAXN];
vector<pii> link[MAXN];
void dfs(int x, int d){
    vis[x]=true;
    dep[x]=d;
    for(int i=1;(1<<i)<=d;i++){
        p[i][x]=p[i-1][p[i-1][x]];
        m[i][x]=min(m[i-1][x],m[i-1][p[i-1][x]]);
        M[i][x]=max(M[i-1][x],M[i-1][p[i-1][x]]);
    }
    for(pii u : link[x]){
        if(!vis[u.fst]){
            p[0][u.fst]=x;
            m[0][u.fst]=M[0][u.fst]=u.snd;
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
    for(int i=0;i<MAXD;i++) fill(m[i],m[i]+MAXN,INF);
    dfs(1,0);
}
void query(){
    for(int mn,mx,x,y=scanf("%d",&Q);Q--;){
        scanf("%d%d",&x,&y);
        mn=1<<20,mx=0;
        if(dep[x]<dep[y]) swap(x,y);
        for(int a=dep[x]-dep[y],i=0;a;i++){
            if(a&(1<<i)){
                a-=(1<<i);
                mn=min(mn,m[i][x]);
                mx=max(mx,M[i][x]);
                x=p[i][x];
            }
        }
        for(int l=MAXD;l&&x!=y;){
            if(p[--l][x]!=p[l][y]){
                mn=min(mn,min(m[l][x],m[l][y]));
                mx=max(mx,max(M[l][x],M[l][y]));
                x=p[l][x],y=p[l][y];
            }
        }
        if(x!=y) mn=min(mn,min(m[0][x],m[0][y])), mx=max(mx,max(M[0][x],M[0][y]));
        printf("%d %d\n",mn,mx);
    }
}
int main(){
    input();
    query();
}
