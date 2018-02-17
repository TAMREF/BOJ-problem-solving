#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;
typedef pair<int,int> pii;
const int MAXV = 803, INF = 1e7;
int V, E, S[4], i, j, x, y, z;
priority_queue<pii,vector<pii>,greater<pii> > q;
vector<pii> adj[MAXV];
int dist[3][MAXV];
pii buk;
void input(){
    scanf("%d%d",&V,&E);
    while(E--){
        scanf("%d%d%d",&x,&y,&z);
        adj[x].push_back(make_pair(z,y));
        adj[y].push_back(make_pair(z,x));
    }
    S[0]=1, scanf("%d%d",&S[1],&S[2]); S[3]=V;
    for(j=0;j<3;j++){
        fill(dist[j]+1,dist[j]+V+1,INF);
        dist[j][S[j]]=0;
    }
}
void dijk(){
    for(i=0;i<3;i++){
    q.push(make_pair(0,S[i]));
    while(!q.empty()){
        buk = q.top(); q.pop();
        if(buk.fst<=dist[i][buk.snd]){
            for(pii &p : adj[buk.snd]){
                if(p.fst+buk.fst<dist[i][p.snd])
                    q.push(make_pair(dist[i][p.snd]=p.fst+buk.fst,p.snd));
            }
        }
    }
    }
}
int output(){
    for(i=1;i<=3;i++) if(dist[0][S[i]]==INF) return -1;
    int P=0, Q=0;
    P=dist[0][S[1]]+dist[1][S[2]]+dist[2][S[3]];
    Q=dist[0][S[2]]+dist[2][S[1]]+dist[1][S[3]];
    return min(P,Q);
}

int main(){
    input();
    dijk();
    printf("%d\n",output());
}