#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7,mx=2e5+5;
struct BIT{
    int N;
    ll a[mx];
    BIT():N(mx){fill(a,a+mx,0);}
    void update(int i,int v){
        for(int j=i;j<N;j+=(j&-j)) a[j]+=1LL*v;
    }
    ll sum(int i){
        ll S=0;
        for(int j=i;j;j-=(j&-j)) S+=a[j];
        return S;
    }
} E,F;
void solve(){
    int N,x; scanf("%d",&N);
    ll acc=1;
    scanf("%d",&x); ++x;
    E.update(x,x); F.update(x,1);
    for(int i=1;i<N;i++){
        ll now=0;
        scanf("%d",&x); ++x;
        ll e=E.sum(x),f=F.sum(x),g=E.sum(mx-1);
        now+=f*x*2-e*2-1LL*i*x+g;
        E.update(x,x);
        F.update(x,1);
        acc=(acc*(now%mod))%mod;
    }
    printf("%lld\n",acc);
}

int main(){
    solve();
}