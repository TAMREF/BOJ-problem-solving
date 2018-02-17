#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    node *l, *r, *p;
    int cnt;
    ll key, sum;
} *tree;
void Update(node *x){
    x->cnt=1; x->sum=x->key;
    if(x->l){
        x->cnt+=x->l->cnt;
        x->sum+=x->l->sum;
    }
    if(x->r){
        x->cnt+=x->r->cnt;
        x->sum+=x->r->sum;
    }
}
void Rotate(node *x){
    node *p = x->p, *b;
    if(!p) return;
    if(x==p->l){
        p->l = b = x->r;
        x->r = p;
    } else{
        p->r = b = x->l;
        x->l = p;
    }
    x->p = p->p;
    p->p = x;
    if(b) b->p = p;
    (x->p?p==x->p->l?x->p->l:x->p->r:tree)=x;
    Update(p); Update(x);
}
void Splay(node *x){
    while(x->p){
        node *p = x->p, *g=p->p;
        if(g) Rotate((x==p->l)==(p==g->l)?p:x);
        Rotate(x);
    }
}
void Find_Kth(int k){
    node *x=tree;
    while(1){
        while(x->l && x->l->cnt>k) x=x->l;
        if(x->l) k-=x->l->cnt;
        if(!k--) break;
        x=x->r;
    }
    Splay(x);
}
void Initialize(int n){
    node *x;
    tree = x = new node;
    x->l=x->r=x->p=NULL;
    x->cnt=n+2; //dummy node
    for(int i=1;i<n+2;i++){
        x->r=new node;
        x->r->p = x;
        x = x->r;
        x->l = x->r = NULL;
        x->cnt = n+2-i;
        x->sum = x->key=0;
    }
}
void Add(int i, ll z){
    Find_Kth(i);
    tree->sum+=z;
    tree->key +=z;
}
void Interval(int l, int r){
    Find_Kth(l-1);
    node *x = tree;
    tree=x->r;
    tree->p=NULL;
    Find_Kth(r-l+1);
    x->r=tree;
    tree->p=x; tree=x;
}
ll Sum(int l, int r){
    Interval(l,r);
    return tree->r->l->sum;
}
int main(){
    int N, Q, x, y, z, w;
    scanf("%d%d",&N,&Q);
    Initialize(N);
    for(int i=1;i<=N;i++){
        scanf("%d",&x);
        Add(i,x);
    }
    while(Q--){
        scanf("%d%d%d%d",&x,&y,&z,&w);
        if(x>y) swap(x,y);
        printf("%lld\n",Sum(x,y));
        Find_Kth(z);
        Add(z,(ll)w-(tree->key));
    }
}
