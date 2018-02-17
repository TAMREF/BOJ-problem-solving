#include <bits/stdc++.h>
using namespace std;
int a[100005], b[100005];
int n,o;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]; a[i]+=a[i-1];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i]; b[i]+=b[i-1];
        if(a[i]==b[i]) o=i;
    }
    cout<<o<<endl;
}