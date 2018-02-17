#include <bits/stdc++.h>
#define va first
#define vb second
#define valid(a) ((a%N!=0)+2*(a%N!=N-1)+4*(a/N!=0)+8*(a/N!=N-1))
using namespace std;
typedef pair<int,int> pii;
const int MX=128;
int dist[MX][MX], cost[MX][MX];
priority_queue<pii,vector<pii>,greater<pii>> q;
int main(){
    int N,t=0;
    rep:
    ++t;
    scanf("%d",&N);
    if(!N) return 0;
    vector<int> dr({-1,1,-N,N});
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) scanf("%d",&cost[i][j]);
    for(int i=0;i<N;i++) fill(dist[i],dist[i]+N,1<<20);
    q.push({dist[0][0]=cost[0][0],0});
    while(!q.empty()){
        pii n=q.top(); q.pop();
        if(n.va>dist[n.vb/N][n.vb%N]) continue;
        int s=valid(n.vb);
        for(int i=0,j;i<4;i++){
            if(s&1<<i){
                j=n.vb+dr[i];
                if(dist[j/N][j%N]>n.va+cost[j/N][j%N])q.push({dist[j/N][j%N]=n.va+cost[j/N][j%N],j});
            }
        }
    }
    printf("Problem %d: %d\n",t,dist[N-1][N-1]);
    goto rep;
}
