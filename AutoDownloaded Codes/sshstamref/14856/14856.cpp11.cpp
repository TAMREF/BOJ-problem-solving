#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f[91]={1,2};

void bfib(){
    for(int i=2;i<90;i++) f[i] = f[i-1]+f[i-2];
}

stack<ll> s;

void zeck(ll n){
    while(n){
        ll c = *(upper_bound(f,f+91,n)-1);
        s.push(c);
        n -= c;
    }
}

int main(){
    ll n;
    bfib();
    cin>>n; zeck(n);
    cout<<s.size()<<endl;
    while(!s.empty()){
        cout<<s.top()<<' ';
        s.pop();
    }
}
