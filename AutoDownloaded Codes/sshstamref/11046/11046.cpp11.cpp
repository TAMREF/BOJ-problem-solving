#include <bits/stdc++.h>
using namespace std;
const int mx=4000006;
int n,i,j,s,p,a[mx]={-1}, r[mx];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[2*i-1];
        a[2*i]=-1;
    }
    n*=2;
    for(i=1;i<=n;i++){
        for(r[i]=(i>s?0:min(n-i,r[2*p-i]));i+r[i]<n&&a[i-r[i]-1]==a[i+r[i]+1]; ++r[i]);
        if(s<i+r[i]) s=i+r[i], p=i;
    }
    for(cin>>n;n--;cout<<(r[i+j-1]>=j-i)<<'\n')
        cin>>i>>j;
}