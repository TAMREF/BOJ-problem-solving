#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mx=300005, mi=530000;
int h, x[mx>>1], y[mx>>1], n, k;
priority_queue<ll> pQ;
struct Idxtree{
    pii tree[mi];
    int L;
    void init(int N,int *y){
        for(L=1;L<=N;L<<=1);
        for(int i=0;i<n;i++) tree[i+L]=pii(y[i],i);
        for(int i=L-1;i;--i) tree[i]=min(tree[i<<1],tree[i<<1|1]);
    }
    int Qi(int s,int e){
        s+=L, e+=L;
        pii t(1e9,1e9);
        while(s<=e){
            if(s&1) t=min(t,tree[s++]);
            if(!(e&1)) t=min(t,tree[e--]);
            s>>=1, e>>=1;
        }
        return t.second;
    }
} rmq;

ll dnc(int s, int e){
    if(s>=e) return 0;
    int pos=rmq.Qi(s,e-1);
    int ph=h;
    h=y[pos];
    ll le=dnc(s,pos), ri=dnc(pos+1,e);
    pQ.push(min(le,ri));
    h=ph;
    return max(le,ri)+1LL*(x[e]-x[s])*(y[pos]-ph);
}
int main(){
    ll ret=0;
    scanf("%d",&n);
    n>>=1;
    for(int i=0;i<n;i++)
        scanf("%*d %*d %d %d",&x[i],&y[i]);
    scanf("%d",&k);
    rmq.init(n,y);
    pQ.push(dnc(0,n-1));
    for(int i=0;i<k&&!pQ.empty();i++){
        ret += pQ.top();
        pQ.pop();
    }
    printf("%lld\n",ret);
}