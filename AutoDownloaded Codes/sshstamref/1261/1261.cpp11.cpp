#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;
typedef pair<int,int> pii;
int N, M, i, j, k, w, x, y, z;
const int MX = 103, INF = 1e7;
bool vis[MX][MX];
char buf[MX], algo[MX][MX];
int dist[MX][MX], dr[4];
priority_queue<pii,vector<pii>,greater<pii> > q;
pii b, c, d;
pii operator+ (pii u, pii v){
    return make_pair(u.fst+v.fst,u.snd+v.snd);
}
inline int chk(int u){
    return (int)(u/M!=N-1) + (int)(u%M!=M-1)*2 + (int)(u/M!=0)*4 + (int)(u%M!=0)*8;
}
void input(){
    scanf("%d%d\n",&M,&N);
    for(i=0;i<N;i++){
        fgets(buf,MX-1,stdin);
        for(j=0;j<M;j++){
            algo[i][j]=buf[j]-'0';
        }
    }
    for(i=0;i<N;i++) fill(dist[i],dist[i]+M,INF);
    dr[0]=M, dr[1]=1, dr[2]=-M, dr[3]=-1;
}
void dijk(){
    q.push(make_pair(dist[0][0]=0,0));
    while(!q.empty()){
        b=q.top(); q.pop(); z=b.snd;
        if(dist[z/M][z%M]>=b.fst){
        vis[z/M][z%M]=true;
        y=chk(z);
        for(k=0;k<4;k++){
            x=z+dr[k];
            if((y&(1<<k)) && !vis[x/M][x%M] && dist[z/M][z%M]+algo[x/M][x%M]<dist[x/M][x%M]){
                q.push(make_pair(dist[x/M][x%M]=dist[z/M][z%M]+algo[x/M][x%M],x));
            }
        }
        }
    }
}
void output(){
    printf("%d\n",dist[N-1][M-1]);
    //for(i=0;i<N;i++,puts("")) for(j=0;j<M;j++) printf("%d ",dist[i][j]);
}
int main(){
    input();
    dijk();
    output();
}
