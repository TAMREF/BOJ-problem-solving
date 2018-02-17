#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    ll v,s;
    int cnt;
    node *p, *l, *r;
} *tree;
void update(node *x){
    x->cnt = 1;
    x->s = x->v;
    if(x->l){
        x->cnt += x->l->cnt;
        x->s +=x->l->s;
    }
    if(x->r){
        x->cnt += x->r->cnt;
        x->s += x->r->s;
    }
}
void rotate(node *x){
    node *p = x->p, *b;
    if(x==p->l){
        p->l = b = x->r;
        x->r = p;
    }else{
        p->r = b= x->l;
        x->l = p;
    }
    x->p = p->p;
    p->p = x;
    if(b) b->p = p;
    (x->p ? p == x->p->l ? x->p->l : x->p->r : tree) = x;
    update(p);
    update(x);
}
void splay(node *x){
    while(x->p){
        node *p = x->p, *g = p->p;
        if(g) rotate((x==p->l)==(p==g->l)?p:x);
        rotate(x);
    }
}
void kth(int k){
    node *x = tree;
    while(1){
        while(x->l && x->l->cnt > k) x=x->l;
        if(x->l) k -= x->l->cnt;
        if(!k--) break;
        x=x->r;
    }
    splay(x);
}
void Init(int n){
    node *x;
    n+=2;
    tree = x = new node;
    x->l = x->r = x->p = nullptr;
    x->cnt = n;
    x->s = x->v = 0;
    for(int i=1;i<n;i++){
        x->r = new node;
        x->r->p = x;
        x = x->r;
        x->l = x->r = nullptr;
        x->cnt = n-i;
        x->s = x->v = 0;
    }
}
void Add(int i, int z){
    kth(i+1);
    tree->s += z;
    tree->v +=z;
}
void Convert(int i, ll v){
    kth(i+1);
    ll d = v-tree->v;
    tree->s += d;
    tree->v += d;
}
void Interval(int l, int r){
    kth(l-1);
    node *x = tree;
    tree = x->r;
    tree->p = nullptr;
    //printf("%p\n",tree);
    kth(r-l+1);
    //printf("%p\n",tree);
    x->r = tree;
    tree->p = x;
    tree = x;
}
ll Sum(int l, int r){
    Interval(l,r);
    return tree->r->l->s;
}
void debug(){
    puts("Here comes a new debugger!");
    for(int i=0;i<7;i++){
        kth(i);
        printf("%lld%c",tree->v," \n"[i==6]);
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    Init(n);
    for(int i=0,x;i<n;i++){
        cin>>x;
        Add(i,x);
    }
    //debug();
    for(int j=0,a,b,c;j<m+k;j++){
        cin>>a>>b>>c;
        if(a==2) cout<<Sum(b,c)<<'\n';
        else Convert(b-1,c);
        //debug();
    }
}