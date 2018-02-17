#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 12345678910LL;
stack<ll> S;
ll ans;
int main(){
    int n;
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll x,y,z;n--;){
        cin>>x;
        if(x){
            for(z=0;!S.empty();){
                y=S.top(); S.pop();
                if(!y){
                    S.push(z?(z*2%mod):1LL);
                    goto fin;
                }
                z+=y;
            }
        }else S.push(x);
        fin:
        x=x;
    }
    for(;!S.empty();S.pop()) ans=(ans+S.top())%mod;
    cout<<ans<<endl;
}