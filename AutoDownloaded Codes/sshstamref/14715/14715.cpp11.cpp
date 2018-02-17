#include <bits/stdc++.h>
using namespace std;
bool chk[1005];
int primes[169]={2}, eop = 1;

void bp(){
    for(int i=3;i<1000;i+=2){
        if(chk[i]) continue;
        primes[eop++] = i;
        for(int j=i*i;j<1000;j+=i+i){
            chk[j] = 1;
        }
    }
}

int facnum(int n){
    if(n==1) return 1;
    int cnt = 0;
    for(int i=0;i<eop;i++){
        while(n % primes[i] == 0){
            n /= primes[i];
            ++cnt;
        }
        if(n==1) break;
    }
    return cnt + (n>1);
}

int main(){
    bp();
    int k, c, i;
    cin>>k;
    c = facnum(k), i=0;
    for(;1<<i < c;i++);
    cout<<i<<endl;
}
