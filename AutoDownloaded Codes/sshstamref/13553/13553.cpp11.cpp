#include <cstdio>
#include <algorithm>
typedef long long ll;
struct Segtree{
    int seg[100005];
    Segtree(){
        for(int i=0;i<100005;i++) seg[i]=0;
    }
    int gs(int i){
        int ans=0;
        for(;i;i-=(i&-i)) ans+=seg[i];
        return ans;
    }
    void update(int idx,int inc){
        for(int i=idx;i<=100000;i+=(i&-i)) seg[i]+=inc;
    }
};
struct query{
    int idx,s,e;
} tam[100005];
int N,Q,K,B,a[100005];
inline int mx(int a,int b){return a>b?a:b;}
inline int mn(int a,int b){return a<b?a:b;}
ll ans,dap[100005];
Segtree S;
int main(){
    scanf("%d%d",&N,&K);
    for(int i=1;i<=N;i++) scanf("%d",&a[i]);
    scanf("%d",&Q); B=mx(10,(int)((double)N/sqrt(Q)));
    for(int i=0;i<Q;i++){
        scanf("%d%d",&tam[i].s,&tam[i].e);
        tam[i].idx=i;
    }
    std::sort(tam,tam+Q,[B](query u, query v)->bool{return u.s/B==v.s/B?u.e<v.e:u.s<v.s;});
    for(int i=0,l=1,r=0;i<Q;i++){
        while(r<tam[i].e){ ++r;
            ans+=S.gs(mn(a[r]+K,100000))-S.gs(mx(a[r]-K-1,0));
            S.update(a[r],1);
        }
        while(r>tam[i].e){
            ans-=S.gs(mn(a[r]+K,100000))-S.gs(mx(a[r]-K-1,0))-1;
            S.update(a[r--],-1);
        }
        while(l>tam[i].s){ --l;
            ans+=S.gs(mn(a[l]+K,100000))-S.gs(mx(a[l]-K-1,0));
            S.update(a[l],1);
        }
        while(l<tam[i].s){
            ans-=S.gs(mn(a[l]+K,100000))-S.gs(mx(a[l]-K-1,0))-1;
            S.update(a[l++],-1);
        }
        dap[tam[i].idx]=ans;
    }
    for(int i=0;i<Q;i++) printf("%lld\n",dap[i]);
}