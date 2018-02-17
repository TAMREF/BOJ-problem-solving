#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull mod = 1e9+7;

inline ull mult(ull a, ull b){
    a %= mod, b %= mod;
    if(a<b) swap(a,b);
    ull ans = 0, x = a;

    for(;b;b>>=1){
        if(b&1) ans = (ans + x)%mod;
        x = (x + x)%mod;
    }

    return ans;
}

priority_queue<ull,vector<ull>,greater<ull>> q;

int n, t;
ull x,y,z;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(cin>>t;t--;){
        cin>>n;
        while(!q.empty()) q.pop();
        for(int i=0;i<n;i++){
            cin>>x;
            q.push(x);
        }

        ull ans = 1;

        while(q.size()>1){
            x = q.top(); q.pop();
            y = q.top(); q.pop();
            z = x * y;
            ans = mult(ans,z);
            q.push(z);
        }

        cout<<ans<<'\n';
    }
}
