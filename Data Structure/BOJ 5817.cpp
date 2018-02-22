#include <bits/stdc++.h>
using namespace std;

const int mx = 200005;

template <typename _T>
struct IndexedTree {
    size_t m;
    _T *A;
    _T ival;
    function<_T(const _T &, const _T &)> F;

    IndexedTree(size_t n, function<_T(const _T &, const _T &)> f, _T iv) {
        for (m = 1; m < n; m <<= 1);
        A = new _T[m << 1];
        F = f;
        ival = iv;
    }

    void Update(size_t idx, _T val) {
        idx |= m;
        A[idx] = val;
        while (idx >>= 1) A[idx] = F(A[idx << 1], A[idx << 1 | 1]);
    }
    _T Query(size_t L, size_t R) {
        _T Lval = ival, Rval = ival;
        L |= m;
        R |= m;
        while (L <= R) {
            if (L & 1) Lval = F(Lval, A[L++]);
            if (!(R & 1)) Rval = F(A[R--], Rval);
            L >>= 1;
            R >>= 1;
        }
        return F(Lval, Rval);
    }
};

int a[mx];
int n, q;

void input(){
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> a[i];
}

void query(){
    IndexedTree<int> mint(n+1, [](int a, int b){return min(a,b);},INT_MAX),
                     maxt(n+1, [](int a, int b){return max(a,b);},0);
    for(int i=1;i<=n;i++){
        mint.Update(a[i],i);
        maxt.Update(a[i],i);
    }
    size_t r = mint.m;
    for(int ty, u, v, w, x;q--;){
        cin >> ty >> u >> v;
        if(ty == 1){
            w = a[u], x = a[v];
            swap(a[u], a[v]);
            mint.Update(x, u);
            maxt.Update(x, u);
            mint.Update(w, v);
            maxt.Update(w, v);
        }else{
            cout << (maxt.Query(u,v) - mint.Query(u,v) == v - u ? "YES":"NO") << '\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    input();
    query();
}
