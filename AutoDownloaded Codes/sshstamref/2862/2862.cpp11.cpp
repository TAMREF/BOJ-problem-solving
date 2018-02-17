#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll F[80] = {1,2};

void bfib(){
    for(int i=2;i<80;i++){
        F[i] = F[i-1] + F[i-2];
    }
}

ll zeck(ll n){
    while(n){
        ll f = *(upper_bound(F,F+80,n)-1);
        if(n == f) return n;
        n -= f;
    }
    return -1;
}

int main(){
    ll n;
    bfib();
    cin>>n;
    cout<<zeck(n)<<endl;
}