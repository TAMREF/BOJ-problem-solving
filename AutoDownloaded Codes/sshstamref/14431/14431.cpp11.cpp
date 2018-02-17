#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;
typedef pair<int,int> pii;
const int INF=1<<30-1;
inline int d(pii u, pii v){
    return (int)sqrt((u.fst-v.fst)*(u.fst-v.fst)+(u.snd-v.snd)*(u.snd-v.snd));
}
bool isprime(int x){
    if(x<3) return x==2;
    if(x%2==0) return false;
    for(int i=3;i*i<=x;i+=2) if(x%i==0) return false;
    return true;
}
pii tam[4005];
vector<int> dis(4005,INF);
vector<pii> adj[4005];
priority_queue<pii,vector<pii>,greater<pii>> q;
int main(){
    int N;
    scanf("%d%d%d%d",&tam[0].fst,&tam[0].snd,&tam[1].fst,&tam[1].snd);
    scanf("%d",&N);
    for(int i=2;i<N+2;i++) scanf("%d%d",&tam[i].fst,&tam[i].snd);
    for(int i=0;i<N+2;i++)
        for(int j=i+1,tmp;j<N+2;j++)
            if(isprime(tmp=d(tam[i],tam[j]))){
                adj[i].push_back({j,tmp});
                adj[j].push_back({i,tmp});
            }
    q.push({dis[0]=0,0}); pii u;
    while(!q.empty()){
        u=q.top(); q.pop();
        if(u.fst<=dis[u.snd]){
            for(pii p : adj[u.snd]){
                if(u.fst+p.snd<dis[p.fst]) q.push({dis[p.fst]=u.fst+p.snd,p.fst});
            }
        }
    }
    printf("%d\n",dis[1]==INF?-1:dis[1]);
}
