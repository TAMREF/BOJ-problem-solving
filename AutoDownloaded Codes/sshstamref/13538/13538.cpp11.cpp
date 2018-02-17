#include <bits/stdc++.h>
using namespace std;
struct pst{
    int cnt;
    pst *l, *r;
};
pst *root[500005];
pst node[10240000];
int ptr, nrt;
void init_pst(){
    root[0]=&node[ptr++];
    root[0]->cnt=0;
    root[0]->l=root[0];
    root[0]->r=root[0];
}
pst *make(pst *now, int s, int e, int y){
    if(y<s||y>e) return now;
    pst *ret = &node[ptr++];
    if(s==e){
        ret->cnt = now->cnt + 1;
        return ret;
    }
    int m=(s+e)>>1;
    ret->l = make(now->l,s,m,y);
    ret->r = make(now->r,m+1,e,y);
    ret->cnt = ret->l->cnt + ret->r->cnt;
    return ret;
}
int maxor(pst *a, pst *b, int v){
    int d=18,s=0,m,e=524287;
    for(;s!=e;--d){
        m=(s+e)>>1;
        if(v>>d&1){
            if(b->l->cnt - a->l->cnt){
                a=a->l; b=b->l; e=m;
            }else{
                a=a->r; b=b->r; s=m+1;
            }
        }else{
            if(b->r->cnt - a->r->cnt){
                a=a->r; b=b->r; s=m+1;
            }else{
                a=a->l; b=b->l; e=m;
            }
        }
    }
    return s;
}
int underx(pst *a, pst *b, int x){
    int s=0,m,e=524287,cnt=0;
    for(;s!=e;){
        m=(s+e)>>1;
        if(x>=m){
            cnt += b->l->cnt - a->l->cnt;
            a=a->r; b=b->r;
            s=m+1;
        }else{
            a=a->l; b=b->l;
            e=m;
        }
    }
    return cnt;
}
int kth(pst *a, pst *b, int k){
    int s=0, m, e=524287;
    for(int c;s!=e;){
        m=(s+e)>>1;
        c = b->l->cnt - a->l->cnt;
        if(k>c){
            k-=c;
            a=a->r; b=b->r;
            s=m+1;
        }else{
            a=a->l; b=b->l;
            e=m;
        }
    }
    return s;
}
int m;
void init(){
    cin>>m;
    init_pst();
}
void query(){
    for(int a,b,c,d;m--;){
        cin>>a>>b;
        switch(a){
        case 1:
            root[nrt+1]=make(root[nrt],0,524287,b);
            ++nrt;
            break;
        case 2:
            cin>>c>>d;
            cout<<maxor(root[b-1],root[c],d)<<'\n';
            break;
        case 3:
            nrt-=b;
            break;
        case 4:
            cin>>c>>d;
            cout<<underx(root[b-1],root[c],d)<<'\n';
            break;
        case 5:
            cin>>c>>d;
            cout<<kth(root[b-1],root[c],d)<<'\n';
            break;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    init();
    query();
}