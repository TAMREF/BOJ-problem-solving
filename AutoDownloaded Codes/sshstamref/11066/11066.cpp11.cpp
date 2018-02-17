#include <bits/stdc++.h>
using namespace std;
int dp[505][505], cost[505];
int n;
void init(){
    for(int i=0;i<505;i++) fill(dp[i],dp[i]+505,INT_MAX);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>cost[i];
        cost[i]+=cost[i-1];
    }
    for(int i=1;i<=n;i++) dp[i][i]=0;
}
void build_dp(){
    for(int d=1;d<n;d++){
        for(int s=1;s+d<=n;s++){
            for(int m=s;m<s+d;m++){
                dp[s][s+d]=min(dp[s][s+d],dp[s][m]+dp[m+1][s+d]+cost[s+d]-cost[s-1]);
            }
        }
    }
    cout<<dp[1][n]<<'\n';
}
int main(){
    int T;
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(cin>>T;T--;){
        init();
        build_dp();
    }
}