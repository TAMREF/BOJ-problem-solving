#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
const int mx=100005;
struct pst{
    pst():l(nullptr),r(nullptr),v(0){}
    int v;
    pst *l, *r;
};
pst node[2500000];
int ptr=1;
void init(pst *now, int s, int e){
    if(s==e) return;
    now->l=&node[ptr++];
    now->r=&node[ptr++];
    int m=(s+e)>>1;
    init(now->l,s,m);
    init(now->r,m+1,e);
}
pst* make(pst *now, int s, int e, int y, int v){
    if(y<s||y>e) return now;
    pst *ret = &node[ptr++];
    if(s==e){
        ret->v= now->v + v;
        return ret;
    }else{
        int m=(s+e)>>1;
        ret->l=make(now->l,s,m,y,v);
        ret->r=make(now->r,m+1,e,y,v);
        ret->v= ret->l->v + ret->r->v;
        return ret;
    }
}
int cnt(pst *now, int s, int e, int y1, int y2){
    if(s>y2||e<y1) return 0;
    if(y1<=s && e<=y2) return now->v;
    int m=(s+e)>>1;
    return cnt(now->l,s,m,y1,y2)+cnt(now->r,m+1,e,y1,y2);
}
pst *root[mx];
ii ci[mx];
int xc[mx], yc[mx], n, q;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>ci[i].first>>ci[i].second;
        xc[i]=ci[i].first,yc[i]=ci[i].second;
    }
    sort(xc,xc+n);
    sort(yc,yc+n);
    for(int i=0;i<n;i++){
        ci[i].first=lower_bound(xc,xc+n,ci[i].first)-xc+1;
        ci[i].second=lower_bound(yc,yc+n,ci[i].second)-yc+1;
    }
    sort(ci,ci+n);
    init(root[0]=&node[0],0,n);
    for(int i=0;i<n;i++){
        root[ci[i].first]=make(root[ci[i].first-1],0,n,ci[i].second,1);
    }
}
void query(){
    for(int a,b,u,v;q--;){
        cin>>a>>b>>u>>v;
        b=upper_bound(xc,xc+n,b)-xc;
        a=lower_bound(xc,xc+n,a)-xc;
        v=upper_bound(yc,yc+n,v)-yc;
        u=lower_bound(yc,yc+n,u)-yc+1;
        //printf("(a,b,u,v)=(%d %d %d %d)\n",a,b,u,v);
        //cout<<cnt(root[b],0,n,u,v)<<' '<<cnt(root[a],0,n,u,v)<<'\n';
        cout<<cnt(root[b],0,n,u,v)-cnt(root[a],0,n,u,v)<<'\n';
    }
}
int main(){
    input();
    query();
}