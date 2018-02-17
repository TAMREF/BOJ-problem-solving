#include <bits/stdc++.h>
#define nil nullptr
using namespace std;
typedef unsigned int unt;
unt comb[11][11];
unt A[100000];

void bcomb(){
    for(int i=0;i<11;i++) comb[i][0] = 1;
    for(int i=1;i<11;i++){
        for(int j=1;j<=i;j++) comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
    }
}

struct node{
    node *l, *r, *p;
    node():l(nil),r(nil),p(nil),v(0){
        memset(sum,0,sizeof(sum));
    }
    unt v, sum[11], cnt;
} *tree;

node G[200005];
int num;

void Update(node *x){
    for(int i=0;i<11;i++) x->sum[i] = 0;
    x->cnt = 1;
    if(x->l){
        x->cnt += x->l->cnt;
        for(int k=0;k<11;k++) x->sum[k] += x->l->sum[k];
    }
    unt pv[11] = {1, x->cnt};
    for(int i=2;i<11;i++) pv[i] = pv[i-1]*pv[1];
    for(int i=0;i<11;i++) x->sum[i] += pv[i] * x->v;
    if(x->r){
        x->cnt += x->r->cnt;
        x->sum[0] += x->r->sum[0];
        for(int k=1;k<11;k++){
            for(int j=0;j<=k;j++){
                x->sum[k] += pv[k-j] * comb[k][j] * x->r->sum[j];
            }
        }
    }
}
void Rotate(node *x){
    node *p = x->p, *b;
    if(x == p->l){
        p->l = b = x->r;
        x->r = p;
    } else {
        p->r = b = x->l;
        x->l = p;
    }
    x->p = p->p;
    p->p = x;
    if(b) b->p = p;
    (x->p ? p == x->p->l ? x->p->l : x->p->r : tree) = x;
    Update(p);
    Update(x);
}

void Splay(node *x){
    node *p, *g;
    while(x->p){
        p = x->p;
        g = p->p;
        if(g) Rotate((x==p->l)==(p==g->l) ? p : x);
        Rotate(x);
    }
}

void kth(int k){
    node *x = tree;
    while (1){
        while( x->l && x->l->cnt > k) x = x->l;
        if( x->l ) k-=x->l->cnt;
        if( !k-- ) break;
        x = x->r;
    }
    Splay(x);
}

void Initialize(int n, unt *a){
    tree = new node();
    node *x = tree;
    for(int i=0;i<n;i++){
        x->r = &G[num++];
        x->r->p = x;
        x = x->r;
        x->v = a[i];
    }
    x->r = &G[num++];
    x->r->p = x;
    Splay(x);
}

void Interval(int l, int r){
    kth(l);
    node *x = tree;
    tree = x->r;
    tree->p = nil;
    kth(r-l+1);
    x->r = tree;
    tree->p = x;
    tree = x;
}

unt Sum(int l, int r, int k){
    Interval(l,r);
    return tree->r->l->sum[k];
}

void Append(int p, unt v){
    kth(p+1);
    node *x = tree->l, *q = &G[num++];
    
    q->v = v;
    
    tree->p = q;
    x->p = q;
    
    tree->l = nil;
    q->r = tree;
    q->l = x;
    
    Update(tree);
    Update(q);
    tree = q;
}

void Delete(int m) {
    kth(m+1);
    node *p = tree;
    tree = p->l;
    tree->p = nil;
    node *x = tree;
    while(x->r) x = x->r;
    x->r = p->r;
    p->r->p = x;
    Splay(x);
    return;
}

void Change(int p, unt v){
    kth(p+1);
    tree->v = v;
    Update(tree);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    bcomb();
    unt n,q,ty,a,b,c; cin>>n;
    for(int i=0;i<n;i++) cin>>A[i];
    Initialize(n,A);
    for(cin>>q;q--;){
        cin>>ty>>a;
        switch(ty){
        case 1:
            cin>>b;
            Append(a,b);
            break;
        case 2:
            Delete(a);
            break;
        case 3:
            cin>>b;
            Change(a,b);
            break;
        case 4:
            cin>>b>>c;
            cout<<Sum(a,b,c)<<'\n';
            break;
        }
    }
}