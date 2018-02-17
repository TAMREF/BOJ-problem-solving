#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Segtree{
    int N,L,R;
    ll V;
    ll seg[4000000], lazy[4000000], a[1000005];
    void cl(){
        memset(seg,0,sizeof(seg));
        memset(lazy,0,sizeof(lazy));
        memset(a,0,sizeof(a));
    }
    ll build(int n, int s, int e){
        if(s==e) return seg[n]=a[s];
        int m=(s+e)>>1;
        return seg[n]=build(n<<1,s,m)+build(n<<1|1,m+1,e);
    }
    ll _sum(int n,int s,int e){
        //Lazy prp.
        if(lazy[n]){
            seg[n]+=lazy[n]*(e-s+1);
            if(s!=e){
                lazy[n<<1]+=lazy[n];
                lazy[n<<1|1]+=lazy[n];
            }
            lazy[n]=0;
        }
        if(e<L||s>R) return 0;
        if(L<=s&&e<=R) return seg[n];
        int m=(s+e)>>1;
        return _sum(n<<1,s,m)+_sum(n<<1|1,m+1,e);
    }
    ll sum(int l,int r){
        L=l,R=r;
        return _sum(1,1,N);
    }
    void _u(int n, int s, int e){
        if(lazy[n]){
            seg[n]+=lazy[n]*(e-s+1);
            if(s!=e){
                lazy[n<<1]+=lazy[n];
                lazy[n<<1|1]+=lazy[n];
            }
            lazy[n]=0;
        }
        if(e<L||s>R) return;
        if(L<=s&&e<=R){
            seg[n]+=V*(e-s+1);
            lazy[n<<1]+=V;
            lazy[n<<1|1]+=V;
            return;
        }
        int m=(s+e)>>1;
        _u(n<<1,s,m);
        _u(n<<1|1,m+1,e);
        seg[n]=seg[n<<1]+seg[n<<1|1];
    }
    void update(int l,int r, ll v){
        L=l,R=r,V=v;
        _u(1,1,N);
    }
} S;
int main(){
    int N,M,K;
    scanf("%d%d%d",&N,&M,&K);
    S.N=N;
    S.cl();
    for(int i=1;i<=N;i++) scanf("%lld",&S.a[i]);
    S.build(1,1,N);
    ll d;
    for(int i=0,x,y,z;i<M+K;i++){
        scanf("%d%d%d",&x,&y,&z);
        if(x==1){
            scanf("%lld",&d);
            S.update(y,z,d);
        }else{
            printf("%lld\n",S.sum(y,z));
        }
    }
}