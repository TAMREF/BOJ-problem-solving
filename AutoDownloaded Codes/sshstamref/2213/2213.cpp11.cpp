#include <bits/stdc++.h>
#define ch(x) (max_element(dp[x],dp[x]+2)-dp[x])
using namespace std;
const int mx=10005;
int w[mx];
int dp[mx][2], vis[mx], n;
vector<int> G[mx], T;
void dfs(int x){
    vis[x]=1;
    dp[x][1]=w[x];
    for(int &u : G[x]){
        if(vis[u]) continue;
        dfs(u);
        dp[x][1]+=dp[u][0];
        dp[x][0]+=max(dp[u][0],dp[u][1]);
    }
}
void track(int x, int st){
    vis[x]=1;
    if(st) T.push_back(x);
    for(int &u : G[x]){
        if(vis[u]) continue;
        if(st) track(u,0);
        else track(u,ch(u));
    }
}
void input(){
   cin>>n;
   for(int i=1;i<=n;i++) cin>>w[i];
   for(int i=1,a,b;i<n;i++){
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
   }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    input();
    dfs(1);
    fill(vis+1,vis+n+1,0);
    track(1,ch(1));
    sort(T.begin(),T.end());
    cout<<dp[1][ch(1)]<<'\n';
    for(int &u : T) cout<<u<<' ';
    cout<<'\n';
}