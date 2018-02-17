#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

inline ll lpow(ll a, ll n){
    ll res = 1, pv = a;
    for(;n;n>>=1){
        if(n&1){
            res = res * pv % mod;
        }
        pv = pv * pv % mod;
    }
    return res;
}

inline ll inv(ll a){
    return lpow(a,mod-2);
}

ll a[1005], ainv[1005], n;
int m;

void input(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a[i];
        ainv[i] = inv(a[i]);
    }
}

void Heaviside(){
    ll ans = 0;
    for(int i=0;i<m;i++){
        ll prod = 1;
        for(int j=0;j<m;j++){
            if(j==i) continue;
            prod = prod * ( mod + 1LL - (a[j] * ainv[i] % mod) ) % mod;
        }
        prod = inv(prod) * lpow(a[i],n) % mod;
        ans = (ans + prod)%mod;
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    input();
    Heaviside();
}
