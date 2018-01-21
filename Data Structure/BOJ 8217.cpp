#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx = 300050;

struct Query{
    int l, r;
    ll c;
} Q[mx];

struct RangeBIT{
    int m;
    ll a[mx];
    RangeBIT(int m=mx-1):m(m){
        fill(a,a+mx,0LL);
    }
    void upd(int i, ll v){
        for(;i<=m;i+=(i&-i)) a[i] += v;
    }
    void upd(int a, int b, ll v){
        upd(a,v);
        upd(b+1,-v);
    }
    void upd(Query& q){
        if(q.l <= q.r){
            upd(q.l,q.r,q.c);
        }else{
            upd(q.l,m,q.c);
            upd(1,q.r,q.c);
        }
    }
    ll gsum(int i){
        ll s = 0;
        for(;i;i-=(i&-i)){
            s += a[i];
        }
        return s;
    }
} I;

vector<int> sec[mx];
vector<int> qs[mx];

ll goal[mx];
int lo[mx], hi[mx];
int n, m, k;

void init(){
    cin >> n >> m;
    for(int i=1,o;i<=m;i++){
        cin >> o;
        sec[o].push_back(i);
    }
    for(int i=1;i<=n;i++){
        cin >> goal[i];
    }
    cin >> k;
    for(int i=1;i<=k;i++){
        cin>> Q[i].l >> Q[i].r >> Q[i].c;
    }
    fill(lo+1,lo+n+1,1);
    fill(hi+1,hi+n+1,k+1);
}

void pbs(){
    bool f = 1;
    vector<int> todo;
    todo.reserve(k);
    while(f){
        f = 0;
        I = RangeBIT(m+5);
        todo.clear();

        for(int i=1;i<=n;i++){
            if(lo[i]<hi[i]){
                f = 1;
                todo.push_back((lo[i]+hi[i])/2);
                qs[(lo[i]+hi[i])/2].push_back(i);
            }
        }

        sort(todo.begin(),todo.end());
        todo.erase(unique(todo.begin(),todo.end()),todo.end());

        int cnt=1;
        //printf("working on\n");
        for(int &t : todo){
            //printf("%d ",t);
            for(;cnt<=t;++cnt){
                I.upd(Q[cnt]);
            }
            for(int &i : qs[t]){
                ll got = 0;
                for(int &j : sec[i]){
                    got += I.gsum(j);
                    if( got > goal[i] ) break;
                }
                if(got >= goal[i]){
                    hi[i] = t;
                }else{
                    lo[i] = t + 1;
                }
            }
        }
        //printf("\n");
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    init();
    pbs();
    for(int i=1;i<=n;i++){
        if(lo[i] <= k) cout << lo[i] << '\n';
        else cout << "NIE" << '\n';
    }
}
