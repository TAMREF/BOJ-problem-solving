#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, A[1000006], B,C;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>A[i];
    cin>>B>>C;
    ll cnt=n;
    for(int i=0;i<n;i++) cnt+=(max(0LL,A[i]-B)/C)+((max(0LL,A[i]-B)%C?1:0));
    cout<<cnt<<endl;
}