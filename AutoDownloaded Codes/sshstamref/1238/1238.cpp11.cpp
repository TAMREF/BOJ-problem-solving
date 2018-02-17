#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;
typedef pair<int,int> pii;
const int MAXV = 1003, INF = 1e7;
int V, E, X, i, j, x, y, z;
priority_queue<pii,vector<pii>,greater<pii> > q;
vector<pii> adj[2][MAXV];
int dist[2][MAXV];
pii buk;
void input(){
    scanf("%d%d%d",&V,&E,&X);
    while(E--){
        scanf("%d%d%d",&x,&y,&z);
        adj[0][x].push_back(make_pair(z,y));
        adj[1][y].push_back(make_pair(z,x));
    }
    for(j=0;j<2;j++){
        fill(dist[j]+1,dist[j]+V+1,INF);
        dist[j][X]=0;
    }
}
void dijk(){
    for(i=0;i<2;i++){
    q.push(make_pair(0,X));
    while(!q.empty()){
        buk = q.top(); q.pop();
        if(buk.fst<=dist[i][buk.snd]){
            for(pii &p : adj[i][buk.snd]){
                if(p.fst+buk.fst<dist[i][p.snd])
                    q.push(make_pair(dist[i][p.snd]=p.fst+buk.fst,p.snd));
            }
        }
    }
    }
}
int output(){
    int MX=0;
    for(i=1;i<=V;i++) MX = max(MX,dist[0][i]+dist[1][i]);
    return MX;
}

int main(){
    input();
    dijk();
    printf("%d\n",output());
}