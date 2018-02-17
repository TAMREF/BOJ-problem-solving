#include <bits/stdc++.h>
#define va second.first
#define vb second.second
#define vc first
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pp;
const int MAXV=50005, MAXE=200005;
int rep[MAXV], sz[MAXV];
int vis[MAXV], mark[MAXE];
int p[17][MAXV], M[17][MAXV], S[17][MAXV], depth[MAXV];
vector<pii> link[MAXV];
vector<pp> edge;
int V, E, MC;
inline int f(int x){return x==rep[x]?x:rep[x]=f(rep[x]);}
void input_and_kruskal(){
    scanf("%d%d",&V,&E);
    for(int i=1;i<=V;i++) rep[i]=i;
    memset(S,-1,sizeof(S));
    fill(sz+1,sz+V+1,1);
    for(int i=0,a,b,co;i<E;i++){
        scanf("%d%d%d",&a,&b,&co);
        edge.push_back({co,{a,b}});
    }
    sort(edge.begin(),edge.end());
    for(int i=0,u,v,w;i<E;i++){
        u=f(edge[i].va), v=f(edge[i].vb), w=edge[i].vc;
        if(u==v) continue;
        if(sz[u]<sz[v]) swap(u,v);
        rep[v]=u;
        sz[u]+=sz[v];
        link[u].push_back({v,w});
        link[v].push_back({u,w});
        MC+=edge[i].vc;
        mark[i]=1;
    }
    for(int i=1;i<=V;i++) f(i);
    if(unique(rep+1,rep+V+1)-rep>2) exit(0*puts("-1"));
}
inline void dist(int& bm, int& bs, int xm, int xs, int ym, int ys){
    bm=max(xm,ym);
    bs=(xm==ym?max(xs,ys):xm>ym?max(xs,ym):max(xm,ys));
}
void dfs(int x, int px, int pc, int d){
    vis[x]=1;
    depth[x]=d;
    p[0][x]=px, M[0][x]=pc;
    for(int i=1;(1<<i)<=d;i++){
        p[i][x]=p[i-1][p[i-1][x]];
        dist(M[i][x],S[i][x],M[i-1][x],S[i-1][x],M[i-1][p[i-1][x]],S[i-1][p[i-1][x]]);
    }
    for(pii u : link[x]) if(!vis[u.first]) dfs(u.first,x,u.second,d+1);
}
int maxlca(int x, int y, int W){
    if(depth[x]<depth[y]) swap(x,y);
    int adj=depth[x]-depth[y], ML=-1, SL=-1,u,v;
    for(int i=0;(1<<i)<=adj;i++){
        if(adj&1<<i){
            u=ML,v=SL;
            dist(ML,SL,u,v,M[i][x],S[i][x]);
            x=p[i][x];
        }
    }
    if(x==y) return ML<W?ML:(SL>=0&&SL<W)?SL:-1;
    for(int i=16;i>=0;i--){
        if(p[i][x]!=p[i][y]){
            u=ML, v=SL; dist(ML,SL,u,v,M[i][x],S[i][x]);
            u=ML, v=SL; dist(ML,SL,u,v,M[i][y],S[i][y]);
            x=p[i][x], y=p[i][y];
        }
    }
    u=ML,v=SL; dist(ML,SL,u,v,M[0][x],S[0][x]);
    u=ML,v=SL; dist(ML,SL,u,v,M[0][y],S[0][y]);
    return ML<W?ML:(SL>=0&&SL<W)?SL:-1;
}
int main(){
    input_and_kruskal();
    dfs(1,0,0,0);
    int delt=INT_MAX;
    for(int i=0,tmp;i<E;i++){
        if(mark[i]) continue;
        tmp=maxlca(edge[i].va,edge[i].vb,edge[i].vc);
        if(tmp<0) continue;
        if(edge[i].vc-tmp>0) delt=min(delt,edge[i].vc-tmp);
    }
    if(delt==INT_MAX) return 0*puts("-1");
    printf("%d\n",MC+delt);
}
