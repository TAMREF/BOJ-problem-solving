#include <bits/stdc++.h>
#define va first
#define vb second

using namespace std;

typedef pair<int,int> pii;

const int mx = 200002, inf = mx + mx + mx;

int lev[mx][2];

vector<pii> G[mx];

int n, m;

void init(){
    cin >> n;
    if(n==1){
        puts("0");
        exit(0);
    }
    cin >> m;
    for(int i=0,a,b,w;i<m;i++){
        cin >> a >> b >> w;
        G[a].push_back({b,w});
        G[b].push_back({a,w});
    }
    lev[0][0] = lev[0][1] = 0;
    for(int i=1;i<n;i++){
        lev[i][0] = lev[i][1] = inf;
    }
}

void BFS(){
    queue<pii> Q;
    Q.emplace(0,0);
    Q.emplace(0,1);
    int l;
    pii t;
    while(!Q.empty()){
        t = Q.front(); Q.pop();
        l = lev[t.va][t.vb];
        for(pii &p : G[t.va]){
            if(t.vb == p.vb || lev[p.va][p.vb] < inf) continue;
            lev[p.va][p.vb] = l + 1;
            Q.emplace(p.va,p.vb);
        }
    }
    int ans = min(lev[n-1][0], lev[n-1][1]);
    cout << (ans == inf ? -1 : ans) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    init();
    BFS();
}
