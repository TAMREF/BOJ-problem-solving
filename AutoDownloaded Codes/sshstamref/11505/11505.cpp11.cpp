#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007, MX=1000005, MSEG=2100000;
ll a[MX], seg[MSEG];
ll powr(ll a, int n){
    if(!n) return 1;
    if(n==1) return a%MOD;
    ll P=powr(a,n>>1),Q=n&1?a:1;
    return (P*P%MOD)*Q%MOD;
}
ll build(int now, int s, int e){
    if(s==e) return seg[now]=a[s];
    int m=(s+e)>>1;
    return seg[now]=build(now<<1,s,m)*build(now<<1|1,m+1,e)%MOD;
}
ll product(int now, int s, int e, int l, int r){
    if(e<l||s>r) return 1;
    if(l<=s&&e<=r) return seg[now];
    int m=(s+e)>>1;
    return product(now<<1,s,m,l,r)*product(now<<1|1,m+1,e,l,r)%MOD;
}
void update(int now, int s, int e, int i, ll d){
    if(i>e||i<s) return;
    int m=(s+e)>>1;
    if(s!=e){
    update(now<<1,s,m,i,d);
    update(now<<1|1,m+1,e,i,d);
    } else{
        seg[now]=d;
        return;
    }
    seg[now]=seg[now<<1]*seg[now<<1|1]%MOD;
}
int main(){
    int N, M, K;
    scanf("%d%d%d",&N,&M,&K);
    for(int i=0;i<N;i++) scanf("%lld",&a[i]);
    build(1,0,N-1);
    for(ll i=M+K,x,y,z,w;i--;){
        scanf("%lld%lld%lld",&x,&y,&z);
        if(x==1){
            update(1,0,N-1,y-1,z);
            a[y-1]=z;
        } else{
            if(y>z) swap(y,z);
            printf("%lld\n",product(1,0,N-1,y-1,z-1));
        }
    }
}