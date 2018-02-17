#include <bits/stdc++.h>
using namespace std;

const int mx = 100005, o = 524288, inf = 1<<30;

struct bship{
    int xs, ys, xe, ye, w;
    bship(){}
    bship(int xs, int ys, int xe, int ye, int w):xs(xs),ys(ys),xe(xe),ye(ye),w(w){}
} B[mx];

struct laser{
    int rc, x, w;
} L[mx];

struct Idxtree{
    int a[o+o];
    void init(){
        fill(a,a+o+o,inf);
    }
    void upd(int i, int t){
        i += o;
        a[i] = min(a[i], t);
        while(i>>1){
            a[i>>1] = min(a[i], a[i^1]);
            i >>= 1;
        }
    }
    int rmq(int s, int e){
        if(s > e) swap(s,e);
        s += o; e += o;
        int t = min(a[s],a[e]);
        while(s <= e){
            t = min({t, a[s], a[e]});
            (++s) >>= 1;
            (--e) >>= 1;
        }
        return t;
    }
};

int xp[mx*3], yp[mx*3], nx, ny;
int n, k, l;
Idxtree R[2];

inline int gidx(int* p, int np, int v){
    return lower_bound(p, p+np, v) - p;
}

void init(){
    cin >> n >> k >> l;
    int cr = 0, cc = 0;
    for(int i=0,w;i<k;i++){
        cin >> xp[2*i] >> yp[2*i] >> xp[2*i+1] >> yp[2*i+1] >> w;
        B[i] = bship(xp[2*i], yp[2*i], xp[2*i+1], yp[2*i+1], w);
    }
    for(int i=0;i<l;i++){
        cin >> L[i].x >> L[i].rc; L[i].w = 0;
        if(L[i].rc)
            xp[2*k + cr++] = L[i].x;
        else
            yp[2*k + cc++] = L[i].x;
    }
    sort(xp, xp + 2*k + cr); nx = unique(xp, xp + 2*k + cr) - xp;
    sort(yp, yp + 2*k + cc); ny = unique(yp, yp + 2*k + cc) - yp;

    for(int i=0;i<k;i++){
        B[i].xs = gidx(xp, nx, B[i].xs) + 1;
        B[i].xe = gidx(xp, nx, B[i].xe) + 1;
        B[i].ys = gidx(yp, ny, B[i].ys) + 1;
        B[i].ye = gidx(yp, ny, B[i].ye) + 1;
    }

    for(int i=0;i<l;i++){
        if(L[i].rc)
            L[i].x = gidx(xp, nx, L[i].x) + 1;
        else
            L[i].x = gidx(yp, ny, L[i].x) + 1;
    }

    R[0].init(); R[1].init();
}

void query(){
    for(int i=0;i<l;i++){
        R[L[i].rc].upd(L[i].x, i);
    }
    for(int i=0;i<k;i++){
        int m = min( R[0].rmq(B[i].ys, B[i].ye), R[1].rmq(B[i].xs, B[i].xe) );
        if(m < inf){
            L[m].w = max(L[m].w, B[i].w);
        }
    }
    for(int i=0;i<l;i++){
        cout << L[i].w << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tc=0;
    for(cin>>tc;tc--;){
        init();
        query();
    }
}
