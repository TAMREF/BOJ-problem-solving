#include <bits/stdc++.h>
using namespace std;

const int mx = 300005;

int k, n;
vector<int> G[mx], C[mx];

void idfs(int x, int p){
    for(int &u : G[x]){
        if(u != p){
            C[x].push_back(u);
            idfs(u,x);
        }
    }
}

int dfs(int x){
    int s = 0;
    for(int &u : C[x]){
        s += dfs(u) + 1;
    }
    return s-k > 0 ? s-k : 0;
}

bool cover(int t){
    k = t;
    return !dfs(1);
}

void input(){
    cin >> n;
    for(int i=1,a,b;i<n;i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    idfs(1,0);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    input();
    int lo = 0, mi, hi = n-1;
    while(lo < hi){
        mi = (lo + hi) >> 1;
        if(cover(mi)) hi = mi;
        else lo = mi + 1;
    }
    cout << hi << '\n';
}