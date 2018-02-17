#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
const int mx=50005, inf = 5e8;
typedef pair<int,int> ii;
vector<ii> G[mx];
int n,m,dist[mx];
void input(){
    cin>>n>>m;
    for(int a,b,c;m--;){
        cin>>a>>b>>c;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }
    fill(dist+2,dist+n+1,inf);
}
void dijk(){
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    pq.push({0,1});
    for(ii z;!pq.empty();){
        z = pq.top(); pq.pop();
        if(z.va>dist[z.vb]) continue;
        for(ii &u : G[z.vb]){
            if(dist[u.va]>u.vb+z.va)
                pq.push({dist[u.va]=u.vb+z.va,u.va});
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    input();
    dijk();
    cout<<dist[n]<<endl;
}