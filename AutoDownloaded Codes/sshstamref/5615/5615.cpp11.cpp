#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef unsigned int ui;

ui modpow(ui a, ui n, ui m){
    ui res = 1, pv = a%m;
    for(;n;n>>=1){
        if(n&1) res = (ll)res * pv % m;
        pv = (ll)pv * pv % m;
    }
    return res;
}

bool isprime(ui x){
    if(x==2 || x==7 || x==61) return true;
    if(x<2 || x%2 == 0) return false;
    ui m = x-1, po, s=0;
    for(;~m&1;++s) m>>=1;
    for(ui t : {2u,7u,61u}){
        po = modpow(t,m,x);
        if( po==x-1 || po == 1) goto avoid;
        for(int i=1;i<s;i++){
            po = (ll)po*po%x;
            if( po == x-1) goto avoid;
        }
        return false;
        avoid:
        continue;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T, cnt=0;
    ui x;
    for(cin>>T;T--;){
        cin>>x;
        if(isprime(x*2+1)) ++cnt;
    }
    cout<<cnt<<endl;
}