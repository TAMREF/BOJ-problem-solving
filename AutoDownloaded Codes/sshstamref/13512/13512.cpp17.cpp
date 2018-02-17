#include <bits/stdc++.h>
using namespace std;

const int mx = 100005, lg = 1;

set<int> S;

int dep[mx], sz[mx];
int dt[mx], par[mx], hidx[mx], head[mx], ord[mx];
int clk, nchain;

vector<int> gph[mx];

void dfs(int x, int p){
    sz[x] = 1;
    for(int &u : gph[x]){
        if(u == p) continue;
        par[u] = x;
        dep[u] = dep[x] + 1;
        dfs(u, x);
        sz[x] += sz[u];
    }
}

void hld(int x, int p){
    int fnd = -1, fsz = -1;
    for(int &u : gph[x]){
        if(u == p) continue;
        if(sz[u] > fsz){
            fsz = sz[u];
            fnd = u;
        }
    }
    if(fnd != -1){
        hidx[fnd] = hidx[x];
        dt[fnd] = ++clk;
        ord[clk] = fnd;
        hld(fnd, x);
    }
    for(int &u : gph[x]){
        if(u == p || u == fnd) continue;
        hidx[u] = ++nchain;
        head[nchain] = u;
        dt[u] = ++clk;
        ord[clk] = u;
        hld(u, x);
    }
}

void toggle(int v){
    if(S.find(dt[v]) == S.end()) S.insert(dt[v]);
    else S.erase(dt[v]);
}

int firstblack(int v){
    int ans = -1;
    while(hidx[1] != hidx[v]){
        int h = dt[head[hidx[v]]];
        auto it = S.lower_bound(h);
        if(it != S.end() && *it <= dt[v]) ans = ord[*it];
        v = par[ head[hidx[v]] ];
    }
    auto it = S.lower_bound(dt[1]);
    if(it != S.end() && *it <= dt[v]) ans = ord[*it];
    return ans;
}

int n, q;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1,u,v;i<n;i++){
        cin >> u >> v;
        gph[u].push_back(v);
        gph[v].push_back(u);
    }
    dt[1] = dep[1] = hidx[1] = head[1] = clk = nchain = ord[1] = 1;
    dfs(1,0);
    hld(1,0);
    cin >> q;
    for(int ty,a;q--;){
        cin >> ty >> a;
        if(ty == 1){
            toggle(a);
        }else{
            cout << firstblack(a) << '\n';
        }
    }
}
