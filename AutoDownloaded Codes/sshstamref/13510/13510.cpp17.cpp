#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int mx = 100005, lg = 17;
const int o = 131072;

struct Idxtree{
    int a[o+o];
    Idxtree(){
        memset(a,0,sizeof(a));
    }

    void update(int i, int v){
        i += o;
        a[i] = v;
        for(;i>>1;i>>=1){
            a[i>>1] = max(a[i], a[i^1]);
        }
    }

	int rMq(int s, int e){
		s += o;
		e += o;
		int ret = -1e9;
		while(s < e){
			if(s%2 == 1) ret = max(ret, a[s++]);
			if(e%2 == 0) ret = max(ret, a[e--]);
			s >>= 1;
			e >>= 1;
		}
		if(s == e) ret = max(ret, a[s]);
		return ret;
	}

};

namespace HLD{
    int n;

    int dep[mx], sz[mx];
    int par[lg][mx], parc[mx];

    Idxtree Idt;

    struct Edge{
        int s, e, w;
        int oppo(int x){
            return s + e - x;
        }
    } edg[mx];

    vector<int> gph[mx];

    int HLDidx[mx], head[mx], dt[mx], numchain, clk;

    void dfs(int x, int p){
        sz[x] = 1;
        int u, w;

        for(int i = 1; i < lg; i++) par[i][x] = par[i-1][ par[i-1][x] ];

        for(int &e : gph[x]){
            u = edg[e].oppo(x); w = edg[e].w;
            if(u == p) continue;

            dep[u] = dep[x] + 1;
            par[0][u] = x;
            parc[u] = w;

            dfs(u,x);
            sz[x] += sz[u];
        }
    }

    int lca(int s, int e){
        if(dep[s] > dep[e]) swap(s,e);

        int dlt = dep[e] - dep[s];
        for(int i = 0; dlt; i++){
            if(dlt & 1) e = par[i][e];
            dlt >>= 1;
        }

        for(int i = lg-1; i>=0; i--){
            if(par[i][s] != par[i][e]){
                s = par[i][s]; e = par[i][e];
            }
        }

        return s == e ? s : par[0][s];
    }

    void hld(int x, int p){
        int fnd = -1, fsz = -1, u, w;
        for(int &e : gph[x]){
            u = edg[e].oppo(x); w = edg[e].w;
            if(u == p) continue;
            if(sz[u] > fsz){
                fsz = sz[u];
                fnd = e;
            }
        }

        if(fnd != -1){
            u = edg[fnd].oppo(x); w = edg[fnd].w;
            HLDidx[u] = HLDidx[x];
            dt[u] = ++clk;
            hld(u, x);
        }

        for(int &e : gph[x]){
            u = edg[e].oppo(x); w = edg[e].w;
            if(e == fnd || u == p) continue;

            HLDidx[u] = ++numchain;
            head[numchain] = u;
            dt[u] = ++clk;
            hld(u, x);
        }
    }

    int qup(int s, int e){
        int ans = 0;
        while(HLDidx[s] != HLDidx[e]){
            ans = max(ans, Idt.rMq(dt[ head[HLDidx[s]] ], dt[s]));
            s = par[0][ head[HLDidx[s]] ];
        }
        ans = max(ans, Idt.rMq(dt[e]+1, dt[s]));
        return ans;
    }

    int query(int s, int e){
        int l = lca(s,e);
        return max(qup(s,l), qup(e,l));
    }
}

using namespace HLD;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<n;i++){
        cin >> edg[i].s >> edg[i].e >> edg[i].w;
        gph[edg[i].s].push_back(i);
        gph[edg[i].e].push_back(i);
    }
    dep[1] = 0;
    dfs(1, 0);
    head[1] = HLDidx[1] = dt[1] = clk = numchain = 1;
    hld(1, 0);
    for(int i=2;i<=n;i++){
        Idt.update(dt[i], parc[i]);
    }
    int q;
    int ty, s, e, v, w;
    for(cin >> q; q--; ){
        cin >> ty;
        if(ty == 1){
            cin >> v >> w;
            if(dep[ edg[v].s ] > dep[ edg[v].e ]) swap(edg[v].s, edg[v].e);
            Idt.update( dt[ edg[v].e ], w );
        }else{
            cin >> s >> e;
            cout << query(s, e) << '\n';
        }
    }
}
