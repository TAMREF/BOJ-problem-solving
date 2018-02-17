#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    for(cin>>t;t--;){
        int l,n,x,mn=INT_MIN, mx=INT_MIN;
        for(cin>>l>>n;n--;){
            cin>>x;
            mn = max(mn, min(x, l-x));
            mx = max(mx, max(x, l-x));
        }
        cout<<mn<<' '<<mx<<'\n';
    }
}