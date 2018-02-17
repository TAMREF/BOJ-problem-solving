#include <bits/stdc++.h>
#define sz(v) ((int)v.size())
#define flow 0
#define bridge 1
#define sink n+m+2
#define empl(x) (1+(x))
#define task(x) (n+1+(x))
using namespace std;


const int maxv = 2003;
const int inf = 1e9;

struct Edge{
    int v,c,r;
    Edge(int v,int c,int r):v(v),c(c),r(r){}
};
typedef vector<Edge>::iterator vei;
vector<Edge> G[maxv];
void addEdge(int s, int e, int c){
    G[s].emplace_back(e,c,sz(G[e]));
    G[e].emplace_back(s,0,sz(G[s])-1);
}

int n,m,k;
int lev[maxv];
vei loop[maxv];

void init(){
    cin>>n>>m>>k;
    addEdge(flow,bridge,k);
    for(int i=1,a,b;i<=n;i++){
        for(cin>>a;a--;){
            cin>>b;
            addEdge(empl(i),task(b),1);
        }
    }
    for(int i=1;i<=n;i++){
        addEdge(flow,empl(i),1);
        addEdge(bridge,empl(i),1);
    }
    for(int j=1;j<=m;j++){
        addEdge(task(j),sink,1);
    }
}

bool bfs(){
    memset(lev,-1,sizeof(lev));
    queue<int> q;
    lev[flow] = 0;
    q.push(flow);
    int h;
    while(!q.empty()){
        h = q.front(); q.pop();
        for(Edge &e : G[h]){
            if(lev[e.v]==-1 && e.c>0){
                lev[e.v] = lev[h] + 1;
                q.push(e.v);
            }
        }
    }
    return lev[sink]!=-1;
}

int dfs(int x, int clim){
    if(x==sink) return clim;
    int t,cap,cret;
    for(vei &r = loop[x];r!=G[x].end();r++){
        t = r->v;
        cap = r->c;
        if(lev[x]+1 == lev[t] && cap>0){
            cret = dfs(t,min(cap,clim));
            if(cret>0){
                r->c -= cret;
                G[t][r->r].c += cret;
                return cret;
            }
        }
    }
    return 0;
}

int maxflow(){
    init();
    int ans = 0, acq;
    while(bfs()){
        for(int i=0;i<maxv;i++) loop[i] = G[i].begin();
        acq = dfs(flow,inf);
        if(!acq) break;
        ans += acq;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cout<<maxflow()<<'\n';
}
