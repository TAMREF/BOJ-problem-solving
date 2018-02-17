#include <bits/stdc++.h>
#define va first.first
#define vb first.second
#define vc second
using namespace std;

typedef pair<int,int> pii;
typedef pair<pii,int> ppap;

const int inf = 1.05e9;
const int me = 10005, mv = 2005, mh = 205;

int dist[mv][mh];
int k, n, m, s, t;

struct Edge{
    int a,b,t,h;
    inline int v(int x){
        return a+b-x;
    }
} E[me];

vector<int> G[mv];
priority_queue<ppap,vector<ppap>,greater<ppap>> pQ;

void input(){
    cin>>k>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=0;j<k;j++){
            dist[i][j] = inf;
        }
    }

    for(int i=0;i<m;i++){
        cin>>E[i].a>>E[i].b>>E[i].t>>E[i].h;
        G[E[i].a].push_back(i);
        G[E[i].b].push_back(i);
    }

    cin>>s>>t;
    for(int i=0;i<k;i++) dist[s][i] = 0;

    pQ.push({{0,0},s}); //(t,h,v)
}

void dijk(){
    ppap z;
    int u, r;
    while(!pQ.empty()){
        z = pQ.top(); pQ.pop();
        if(z.vc == t) break;
        if(z.va > dist[z.vc][z.vb]) continue;
        for(int &e : G[z.vc]){
            u = E[e].v(z.vc);
            r = z.vb + E[e].h;
            if( r < k && dist[u][r] > dist[z.vc][z.vb] + E[e].t ){
                dist[u][r] = dist[z.vc][z.vb] + E[e].t;
                pQ.push({{dist[u][r], r}, u});
            }
        }
    }
}

void output(){
    int ans = *min_element(dist[t],dist[t] + k);
    cout<<(ans==inf?-1:ans)<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    input();
    dijk();
    output();
    //debug();
}
