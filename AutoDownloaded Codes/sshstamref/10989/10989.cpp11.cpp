#include <bits/stdc++.h>
using namespace std;
int cnt[10001];
int n;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0,x;i<n;i++){
        cin>>x; ++cnt[x];
    }
    for(int i=1;i<=10000;i++)
        for(;cnt[i]--;cout<<i<<'\n');
}