#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Segtree{
    ll arr[1048576], seg[2098000];
    int N,i,l,r;
    ll v;
    ll _geti(int now,int s,int e){
        int m;
        while(1){
        if(seg[now]){
            if(s==e) arr[s]+=seg[now];
            else{
                seg[now<<1]+=seg[now];
                seg[now<<1|1]+=seg[now];
            }
            seg[now]=0;
        }
        if(s==e) return arr[s];
        if(i<s||i>e) return 0;
        m=(s+e)>>1;
        now<<=1;
        i<=m?e=m:(s=m+1,now|=1);
        }
    }
    ll geti(int _i){
        i=_i;
        return _geti(1,0,N-1);
    }
    void _update(int now,int s,int e){
        if(seg[now]){
            if(s==e) arr[s]+=seg[now];
            else{
                seg[now<<1]+=seg[now];
                seg[now<<1|1]+=seg[now];
            }
            seg[now]=0;
        }
        if(s>r||e<l) return;
        if(l<=s&&e<=r){
            if(s!=e){
                seg[now<<1]+=v;
                seg[now<<1|1]+=v;
            }else{
                arr[s]+=v;
            }
            return;
        }
        int m=(s+e)>>1;
        _update(now<<1,s,m);
        _update(now<<1|1,m+1,e);
    }
    void update(int _l,int _r, ll _v){
        if(_l>_r) return;
        l=_l,r=_r,v=_v;
        _update(1,0,N-1);
    }
} S;
int dt[1<<19], ft[1<<19], ti;
int sal[1<<19];
string buf;
int Q, N;
vector<int> C[1<<19];
void dfs(int x){
    S.arr[ti]=sal[x];
    dt[x]=ti++;
    for(int u : C[x]) dfs(u);
    S.arr[ti]=sal[x];
    ft[x]=ti++;
}
void input(){
    cin>>N>>Q;
    S.N=N<<1;
    for(int i=0,bo;i<N;i++){
        cin>>sal[i];
        if(!i) continue;
        cin>>bo;
        C[bo-1].push_back(i);
    }
    dfs(0);
}
void query(){
    getline(cin,buf);
    char q;
    int a; ll x;
    for(;Q--;){
        cin>>q;
        if(q=='p'){
            cin>>a>>x;
            S.update(dt[a-1]+1,ft[a-1]-1,x);
        }else{
            cin>>a;
            printf("%lld\n",S.geti(dt[a-1]));
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    input();
    query();
    return 0;
}