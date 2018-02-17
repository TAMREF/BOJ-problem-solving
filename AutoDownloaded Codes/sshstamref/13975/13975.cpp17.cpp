#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

priority_queue<ll,vector<ll>,greater<ll>> pq;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t, n;
    ll x,y,ans;
    for(cin>>t;t--;){
        ans = 0;
        for(cin>>n;n--;){
            cin>>x;
            pq.push(x);
        }
        while(pq.size() > 1){
            x = pq.top(); pq.pop();
            y = pq.top(); pq.pop();
            ans += (x+y);
            pq.push(x+y);
        }
        pq.pop();
        cout<<ans<<'\n';
    }
}