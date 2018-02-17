#include <bits/stdc++.h>
using namespace std;

const int mx = 1e6+5, ms = 2097152;
const int o = 2097152;

struct Idxtree{
    int a[o+o];
    void init(int *r, int n){
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++) a[o+i] = r[i];
        for(int x = o; x > 1; x >>= 1){
            for(int y = x; y < x + x; y += 2){
                a[y >> 1] = max(a[y], a[y^1]);
            }
        }
    }
    int rMq(int s, int e){
        if(s > e) return 0;
        s += o; e += o;
        int r = max(a[s],a[e]);
        while(s <= e){
            r = max({r, a[s], a[e]});
            (++s) >>= 1;
            (--e) >>= 1;
        }
        return r;
    }
} I;

vector<int> gph[mx], chi[mx];
int dt[mx], ft[mx], clk;
int cost[mx], ord[ms];
int n;

void dfs(int x, int p){
    dt[x] = clk++;
    ord[dt[x]] = cost[x];

    for(int &u : gph[x]){
        if(u == p) continue;
        chi[x].push_back(u);
        dfs(u,x);
    }

    ft[x] = clk++;
    ord[ft[x]] = cost[x];
}

void input(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> cost[i];
    for(int i=1,a,b;i<n;i++){
        cin >> a >> b;
        gph[a].push_back(b);
        gph[b].push_back(a);
    }
    dfs(1,0);
    I.init(ord,n+n);
}

void work(){
    int ans = 0;
    for(int i=1;i<=n;i++){
        int lans = 0;
        for(int &u : chi[i]){
            lans += I.rMq(dt[u],ft[u]);
        }
        lans += max(I.rMq(1,dt[i]-1), I.rMq(ft[i]+1,2*n-1));
        ans = max(ans,lans);
    }
    printf("%d\n",ans);
}

int main(){
    input();
    work();
}
