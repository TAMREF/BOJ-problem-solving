#include <bits/stdc++.h>
using namespace std;

const int off = 100001;
const int mx = 200005;
const int o = 262144;
const int minf = 0;

int A[100005];

list<int> sum[mx];

struct Idxtree{
    int a[o+o];
    Idxtree(){
        fill(a,a+o+o,minf);
    }
    void upd(int i, int v){
        i += o;
        a[i] = v;
        for(;i>1;i>>=1){
            a[i>>1] = max(a[i],a[i^1]);
        }
    }
} I;

inline int eval(list<int>& L){
    return L.size() > 1 ? L.back() - L.front() : minf;
}

struct Query{
    int s, e, i;
} Que[100005];

void rmv(int i, bool f){
    if(f){
        sum[A[i] + off].pop_front();
    }else{
        sum[A[i] + off].pop_back();
    }
    I.upd(A[i] + off, eval(sum[A[i] + off]));
}

void ins(int i, bool f){
    if(f){
        sum[A[i] + off].push_front(i);
    }else{
        sum[A[i] + off].push_back(i);
    }
    I.upd(A[i] + off, eval(sum[A[i] + off]));
}

int n, q, b;
int ans[100005];

void input(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> A[i];
        A[i] += A[i-1];
    }
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> Que[i].s >> Que[i].e;
        if(Que[i].s > Que[i].e) swap(Que[i].s, Que[i].e);
        --Que[i].s;
        Que[i].i = i;
    }

    b = sqrt(n + 5);

    sort(Que,Que+q,[&](Query &u, Query &v){
            return u.e / b == v.e / b ? u.s < v.s : u.e < v.e;
         });
}

void query(){
    ins(0,false);
    for(int i=0, lo=0, hi=0;i<q;i++){
        int nlo = Que[i].s, nhi = Que[i].e;
        for(int i = hi + 1; i <= nhi ; ++i) ins(i,false);
        for(int i = hi ; i > nhi ; --i) rmv(i,false);
        for(int i = lo ; i < nlo ; ++i) rmv(i,true);
        for(int i = lo - 1; i >= nlo ; --i) ins(i,true);
        lo = nlo;
        hi = nhi;

        ans[Que[i].i] = I.a[1];
    }
}

void output(){
    for(int i=0;i<q;i++) cout << ans[i] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    input();
    query();
    output();
}
