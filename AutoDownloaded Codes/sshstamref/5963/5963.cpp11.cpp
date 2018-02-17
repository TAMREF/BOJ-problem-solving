#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
ll fac[21]={1};
ll P;
int n,q;
int line[20];
vector<int> ind;
void init(){
    for(int i=1;i<=20;i++) fac[i]=fac[i-1]*i;
    cin>>n>>q;
}
void puery(){
    cin>>P; --P;
    ind.resize(n);
    iota(all(ind),1);
    for(int i=n-1;i>=0;i--){
        line[i]=ind[P/fac[i]];
        ind.erase(ind.begin()+(P/fac[i]));
        P%=fac[i];
    }
    for(int i=n-1;i>=0;i--) cout<<line[i]<<' ';
    cout<<'\n';
}
void query(){
    ll ord=1;
    ind.resize(n);
    iota(all(ind),1);
    for(int i=0;i<n;i++){
        cin>>line[i];
        ord+=fac[n-1-i]*(lower_bound(all(ind),line[i])-ind.begin());
        ind.erase(lower_bound(all(ind),line[i]));
    }
    cout<<ord<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    init();
    for(char c;q--;){
        cin>>c;
        if(c=='P') puery();
        else query();
    }
}