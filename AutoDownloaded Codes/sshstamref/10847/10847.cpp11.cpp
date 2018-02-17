#include <bits/stdc++.h>
#define va first
#define vb second
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
typedef pair<int,int> pii;
const int mx=30005;
int dist[mx], B[mx], P[mx];
vector<int> C[mx];
int N,M;
void input(){
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;i++){
        scanf("%d%d",&B[i],&P[i]);
        C[B[i]].push_back(P[i]);
    }
    for(int i=0;i<N;i++){
        sort(all(C[i]));
        C[i].erase(unique(all(C[i])),C[i].end());
    }
    fill(dist,dist+N,(int)1e9);
}
void dijk(int s){
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push(mp(dist[s]=0,s));
    pii t;
    int x,o,c;
    while(!q.empty()){
        t=q.top(); q.pop();
        if(t.va>dist[t.vb]) continue;
        for(int p : C[t.vb]){
            for(x=1,o=t.vb+p,c=t.va+1;o<N;++x,o+=p,++c){
                if(dist[o]>c){
                    q.push(mp(dist[o]=c,o));
                    if(binary_search(all(C[o]),p)) break;
                }
            }
            for(x=1,o=t.vb-p,c=t.va+1;o>=0;++x,o-=p,++c){
                if(dist[o]>c){
                    q.push(mp(dist[o]=c,o));
                    if(binary_search(all(C[o]),p)) break;
                }
            }
        }
    }
}
int main(){
    input();
    dijk(B[0]);
    printf("%d\n",dist[B[1]]==(int)1e9?-1:dist[B[1]]);
}