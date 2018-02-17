#include <bits/stdc++.h>
using namespace std;
const int mx=400005, ms=1049000;
struct Segtree{
    int arr[mx], seg[ms];
    int n, l, r, i, v;
    int _geti(){
        int now=1,s=0,e=n-1;
        while(s<=e){
            if(seg[now]){
                if(s==e) arr[s]=max(arr[s],seg[now]);
                else{
                    seg[now<<1]=max(seg[now<<1],seg[now]);
                    seg[now<<1|1]=max(seg[now<<1|1],seg[now]);
                }
                seg[now]=0;
            }
            if(s==e) return arr[s];
            int m=(s+e)>>1;
            now<<=1;
            i>m?(now|=1,s=m+1):e=m;
        }
    }
    int geti(int _i){
        i=_i;
        return _geti();
    }
    void _upd(int now, int s, int e){
        if(seg[now]){
            if(s==e) arr[s]=max(arr[s],seg[now]);
            else{
                seg[now<<1]=max(seg[now<<1],seg[now]);
                seg[now<<1|1]=max(seg[now<<1|1],seg[now]);
            }
            seg[now]=0;
        }
        if(l>e||s>r) return;
        if(l<=s&&e<=r){
            if(s!=e){
                seg[now<<1]=max(seg[now<<1],v);
                seg[now<<1|1]=max(seg[now<<1|1],v);
            }else{
                arr[s]=max(arr[s],v);
            }
            return;
        }
        int m=(s+e)>>1;
        _upd(now<<1,s,m);
        _upd(now<<1|1,m+1,e);
    }
    void update(int _l, int _r, int _v){
        l=_l, r=_r, v=_v;
        _upd(1,0,n-1);
    }
    void debug(){
        for(int i=0;i<n;i++) printf("S.arr[%d]=%d\n",i,arr[i]);
    }
} S;
int n,q;
int dep[mx], dt[mx>>1], ft[mx>>1];
int p[20][mx>>1];
int ti;
vector<int> C[mx];
void dfs(int x, int d=0){
    dt[x]=ti++;
    dep[x]=d;
    for(int i=1;1<<i<=d;i++) p[i][x]=p[i-1][p[i-1][x]];
    for(int u : C[x]){
        dfs(u,d+1);
    }
    ft[x]=ti++;
    dep[x]=d;
}
int lca(int u, int v){
    if(dep[u]<dep[v]) swap(u,v);
    int df=dep[u]-dep[v];
    for(int i=0;df;++i){
        if(df&1<<i){
            df^=(1<<i);
            u=p[i][u];
        }
    }
    for(int L=19;L>=0&&(u!=v);--L){
        if(p[L][u]!=p[L][v]) u=p[L][u],v=p[L][v];
    }
    return u==v?u:p[0][u];
}
void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        cin>>p[0][i];
        C[p[0][i]].push_back(i);
    }
    dfs(1);
    S.n=n<<1;
}
void query(){
    for(int b,c,d,v,w;q--;){
        cin>>b>>c>>d;
        v=dep[lca(b,c)]>=max(S.geti(dt[b]),S.geti(dt[c]));
        puts(v?"YES":"NO");
        if(d){
            w=v?b:c;
            S.update(dt[w],ft[w],dep[w]);
        }
    }
}
int main(){
    init();
    query();
}