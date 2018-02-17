#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll x[100005];
int n;

void input(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> x[i];
}

ll pro(ll t){
    ll cost = 0;
    for(int i=0;i<n;i++) cost += llabs(x[i] - (ll)i * t);
    return cost;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    input();
    ll lo = 0, mi, hi = 1000000000;
    while(lo < hi){
        mi = (lo + hi) >> 1;
        if(pro(mi) >= pro(mi+1)){
            lo = mi + 1;
        }else{
            hi = mi;
        }
    }
    cout << pro(lo) << '\n';
}
