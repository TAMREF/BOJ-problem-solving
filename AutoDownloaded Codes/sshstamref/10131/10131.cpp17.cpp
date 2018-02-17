#include <bits/stdc++.h>
using namespace std;

const int mx = 500005;
typedef pair<int,int> pii;

int vis[mx], cost[mx], sz[mx];
vector<int> gph[mx];
int n;

bool cmp(pii u, pii v){
    return u.first - u.second > v.first - v.second;
}

int dfs(int x){
    vis[x] = 1;
    sz[x] = 1;
    vector<pii> sub;
    for(int &u : gph[x]){
        if(!vis[u]){
            int d = dfs(u);
            sub.emplace_back(d, 2 * sz[u]);
            sz[x] += sz[u];
        }
    }
    sort(sub.begin(),sub.end(),cmp);
    int s = sub.size();
    int mc = -1, psum = 0;
    for(int i=0;i<s;i++){
        mc = max(mc, sub[i].first + psum);
        psum += sub[i].second;
    }
    if(x!=1) return max(mc, cost[x]) + 1;
    return max(mc, cost[1] + 2 * (n - 1));
}

void input(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> cost[i];
    for(int i=1,a,b;i<n;i++){
        cin >> a >> b;
        gph[a].push_back(b);
        gph[b].push_back(a);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    input();
    cout << dfs(1) << endl;
}
