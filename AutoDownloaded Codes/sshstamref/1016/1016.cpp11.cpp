#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool s[1000005];
int main(){
    ll a, b; cin>>a>>b;
    for(ll i=2;i*i<=b;i++){
        for(ll j=a/(i*i)*i*i;j<=b;j+=i*i){
            if(j<a) continue;
            s[j-a]=true;
        }
    }
    int cnt=0;
    for(int i=0;i<=b-a;i++) if(!s[i]) ++cnt;
    cout<<cnt;
}