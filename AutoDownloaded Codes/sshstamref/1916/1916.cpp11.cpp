#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;
typedef long long ll;
typedef pair<ll,int> Pair;
const int MAXV = 1003, MAXE = 100005;
const ll INF = 1e15;
int V, E, i, j, k, x, y, z, st, ds;
Pair buk;
priority_queue<Pair,vector<Pair>,greater<Pair> > pq;
vector<Pair> adj[MAXV];
vector<ll> ans={0};
void input(){
    scanf("%d%d",&V,&E);
    for(i=0;i<E;i++){
        scanf("%d%d%d",&x,&y,&z);
        adj[x].push_back(make_pair((ll)z,y));
    }
    scanf("%d%d",&st,&ds);
    for(i=1;i<=V;i++) ans.push_back(INF);
    pq.push(make_pair(0,st)); ans[st]=0;
}
void dijk(){
    while(!pq.empty()){
        buk = pq.top();
        pq.pop();
        if(buk.fst<=ans[buk.snd]){
            for(Pair &u : adj[buk.snd]){
                if(buk.fst+u.fst<ans[u.snd]) pq.push(make_pair(ans[u.snd]=buk.fst+u.fst,u.snd));
            }
        }
    }
}
void output(){
    printf("%d\n",ans[ds]);
}
int main(){
    input();
    dijk();
    output();
}