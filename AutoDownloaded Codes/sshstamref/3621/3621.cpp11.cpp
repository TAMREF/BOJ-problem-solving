#include <bits/stdc++.h>
using namespace std;
int n,d,x;
long long ans;
int p[100005], dp[100005];
int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>d;
    for(int i=d+1;i<=n;i++){
        dp[i]=dp[i+1-d]+1;
    }
    for(int i=0;i<n;i++){
        cin>>x;
        ++p[x];
    }
    for(int i=0;i<=n;i++) ans+=dp[p[i]];
    cout<<ans<<endl;
}