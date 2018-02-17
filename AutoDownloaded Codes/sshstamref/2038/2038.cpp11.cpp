#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> g;
vector<ll> h;

inline int f(ll x){
    return upper_bound(g.begin(),g.end(),x) - g.begin();
}

int main(){
    g.reserve(20000); h.reserve(20000);
    ll n; cin >> n;
    if(n == 1) return 0 * puts("1");
    g.push_back(1); h.push_back(1);
    g.push_back(2); h.push_back(3);
    for(int i=1;g.back() <= n;i++){
        g.push_back( g.back() + f(f(g.back())));
    }
    cout << g.size() - 1 << endl;
}
