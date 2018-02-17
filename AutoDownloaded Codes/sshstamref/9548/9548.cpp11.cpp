#include <bits/stdc++.h>
using namespace std;
struct node{
    node *l, *r, *p;
    int cnt;
    char c;
    node():l(0),r(0),p(0),c(0){}
    node(char ch):l(0),r(0),p(0),c(ch){}
} *tree;

void Update(node *x){
    x->cnt = 1;
    if(x->l){
        x->cnt += x->l->cnt;
    }
    if(x->r){
        x->cnt += x->r->cnt;
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
    (x->p ? p==x->p->l ? x->p->l : x->p->r : tree) = x;
    Update(p);
    Update(x);
}

void Splay(node *x){
    node *p, *g;
    while(x->p){
        p = x->p; g = p->p;
        if(g) Rotate((x==p->l) == (p==g->l)? p : x);
        Rotate(x);
    }
}

void Kth(int k){
    node *x = tree;
    while(1){
        while(x->l && x->l->cnt > k) x = x->l;
        if(x->l) k-= x->l->cnt;
        if(!k--) break;
        x = x->r;
    }
    Splay(x);
}


char buf[1000006];
int n;

void InitSplay(){
    node *x;
    tree = x = new node();
    x->cnt = n+2;
    for(int i=0;i<n;i++){
        x->r = new node(buf[i]);
        x->r->p = x;
        x = x->r;
        x->cnt = n+1-i;
    }
    x->r = new node();
    x->r->p = x;
    x = x->r;
    x->cnt = 1;
}

void Append(int X, int k){
    Kth(X);
    //printf("root = %p, r = %p\n",tree, tree->r);
    node *x = new node(buf[0]), *h = x, *v = tree->r;
    for(int i=1;i<k;i++){
        x->r = new node(buf[i]);
        x->r->p = x;
        x = x->r;
    }
    x->r = v;
    v->p = x;
    h->p = tree;
    tree->r = h;
    Splay(v);
    n+=k;
}

void Print(int X, int Y){
    for(int i=X+1;i<=Y+1;i++){
        Kth(i);
        putchar(tree->c);
    }
    putchar(10);
}

int main(){
    int T,k,l;
    scanf("%d\n",&T);
    for(;T--;){
        scanf("%s",buf);
        n=strlen(buf);
        InitSplay();
        for(char q;;){
            scanf("%*c%c",&q);
            if(q=='E'){
                fgets(buf,100,stdin);
                goto enD;
            }else if(q=='I'){
                scanf(" %s %d",buf,&k);
                Append(k,strlen(buf));
            }else if(q=='P'){
                scanf("%d %d",&k,&l);
                Print(k,l);
            }
        }
        enD:
        T = T;
    }
}