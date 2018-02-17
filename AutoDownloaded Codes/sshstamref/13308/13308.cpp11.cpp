#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;
typedef long long ll;
typedef pair<ll,int> Pair;
typedef pair<ll,pair<int,int> > ppap;
const int MX = 2505;
const ll INF = 1e15;
int V, E, i, j, k=1, x, y, z, tam, ding;
ll D[MX][MX], oil[MX];
vector<Pair> adj[MX];
priority_queue<ppap,vector<ppap>,greater<ppap> > q;
void input(){
    scanf("%d%d",&V,&E);
    for(i=1;i<=V;i++) scanf("%lld",&oil[i]);
    while(E--){
        scanf("%d%d%d",&x,&y,&z);
        adj[x].push_back(make_pair(z,y));
        adj[y].push_back(make_pair(z,x));
    }
    for(i=1;i<=V;i++){
        fill(D[i]+1,D[i]+V+1,INF);
    }
    D[1][1]=0;
}
void dijk(){
    ppap b;
    q.push(make_pair(0,make_pair(1,1)));
    while(!q.empty()){
        b = q.top(); q.pop();
        tam = b.snd.fst, ding=b.snd.snd;
        if(b.fst<=D[tam][ding]){
            for(Pair &p : adj[tam]){
                int koi = oil[p.snd]<oil[ding]?p.snd:ding;
                if(b.fst+oil[ding]*p.fst<D[p.snd][koi]){
                    q.push(make_pair(D[p.snd][koi]=b.fst+oil[ding]*p.fst,make_pair(p.snd,koi)));
                }
            }
        }
    }
}
void output(){
    ll ans = INF;
    for(i=1;i<=V;i++) ans= min(ans,D[V][i]);
    printf("%lld\n",ans);
}
int main(){
    input();
    dijk();
    output();
    return 0;
}