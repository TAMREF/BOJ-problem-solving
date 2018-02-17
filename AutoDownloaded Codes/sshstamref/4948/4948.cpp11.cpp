#include <bits/stdc++.h>
using namespace std;
const int mx = 123456*2;
int primes[30000]={2}, eop=1;
bool chk[mx];

void bp(){
    for(int i=3;i < mx ;i+=2){
        if(chk[i]) continue;
        primes[eop++] = i;
        for(long long j = 1LL*i*i ; j < mx ; j += (i+i)){
            chk[j] = 1;
        }
    }
}

int main(){
    bp();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int n;;){
        cin>>n;
        if(!n) return 0;
        cout<<upper_bound(primes,primes+eop,n+n) - upper_bound(primes,primes+eop,n)<<'\n';
    }
}