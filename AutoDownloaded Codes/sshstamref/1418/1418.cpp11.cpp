#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef pair<int,int> pii;

priority_queue<pii,vector<pii>,greater<pii>> q;

int primes[25], eop=0;

void buildprime(int k){
    if(k>=2) primes[eop++] = 2;
    for(int i=3;i<=k;i+=2){
        for(int j=3;j*j<=i;j+=2){
            if(i%j==0) goto fail;
        }
        primes[eop++] = i;
        fail:
            i=i;
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    buildprime(k);
    for(int i=0;i<eop;i++) q.push({primes[i],i});
    int cnt = 1;
    while(!q.empty()){
        pii z = q.top(); q.pop();
        if(z.va <= n) ++cnt;
        for(int i=z.vb;i<eop;i++){
            if(z.va * primes[i] > n) break;
            q.push({z.va * primes[i], i});
        }
    }
    cout<<cnt<<endl;
}