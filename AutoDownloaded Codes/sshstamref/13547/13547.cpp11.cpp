#include <bits/stdc++.h>
using namespace std;
const int mx = 100005, mxlgx = 1.8e6+5;
struct pst{
    pst *l, *r;
    int v;
} node[mxlgx];

int nnode, n, tn;
pst *root[mx];

int las[1000005];

void init(){
    root[0] = &node[nnode++];
    root[0] -> l = root[0];
    root[0] -> r = root[0];
    root[0] -> v = 0;
}

pst *make(pst *now, int s, int e, int y){
    if(y<s||y>e) return now;
    pst *ret = &node[nnode++];
    if(s==e){
        ret->v = now->v + 1;
        return ret;
    }
    int m=(s+e)>>1;
    ret->l = make(now->l,s,m,y);
    ret->r = make(now->r,m+1,e,y);
    ret->v = ret->l->v + ret->r->v;
    return ret;
}

int underx(pst *u, pst *l, int x){
    int s=0, m, e=n, C=0;
    for(;s!=e;){
        m=(s+e)>>1;
        if(x>m){
            C += u->l->v - l->l->v;
            u = u->r; l = l->r;
            s = m + 1;
        }else{
            u = u->l; l = l->l;
            e = m;
        }
    }
    return C;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    init();
    cin>>n;
    tn = n;
    for(int b=1;b<=tn;b<<=1) tn |= b;

    for(int i=1,y;i<=n;i++){
        cin>>y;
        root[i] = make(root[i-1], 0, n, las[y]);
        las[y] = i;
    }

    int q,a,b;
    for(cin>>q;q--;){
        cin>>a>>b;
        cout<<underx(root[b],root[a-1],a)<<'\n';
    }
}