#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx=1<<20;
const ll mod=1e9+7;
ll C[mx];
int N,M,G;
ll pow2(ll n){
    ll ret = 1, pv = 2;
    for(;n;n>>=1){
        if(n&1) ret = (ret * pv)%mod;
        pv = pv * pv % mod;
    }
    return ret;
}
void input(){
    cin>>N>>M;
    for(int i=0,Ki,g,b;i<N;i++){
        b=0;
        for(cin>>Ki;Ki--;){
            cin>>g;
            b|=1<<(--g);
        }
        ++C[b];
    }
}
void dnc(int s, int e){
    if(e-s==1){
        C[s]=pow2(C[s]);
        return;
    }
    int m=(s+e)>>1;
    for(int i=s;i<m;i++) C[i+m-s]+=C[i];
    dnc(s,m); dnc(m,e);
    for(int i=s;i<m;i++) C[i+m-s]=((C[i+m-s]-C[i])%mod+mod)%mod;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    input();
    dnc(0,1<<M);
    printf("%lld\n",C[(1<<M)-1]);
}