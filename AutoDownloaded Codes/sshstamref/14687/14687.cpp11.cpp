#include <bits/stdc++.h>
using namespace std;
int n;
int p[105],q[105];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>p[i];
    sort(p,p+n,greater<int>());
    reverse(p,p+n/2);
    for(int i=0;i<n/2;i++) q[2*i+1]=p[i];
    for(int i=0;i<=n/2;i++) q[2*i]=p[n/2+i];
    for(int i=0;i<n;i++) cout<<q[i]<<" \n"[i==n-1];
}