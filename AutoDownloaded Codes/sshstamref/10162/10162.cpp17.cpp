#include <bits/stdc++.h>
using namespace std;

int dp[1005], ans[1005][3];
int cac[31];
int main(){
    cac[1] = 2; cac[6] = 1; cac[30] = 0;
    for(int t=1;t<=1000;t++){
        dp[t] = INT_MAX;
        for(int u : {1,6,30}){
            if(t < u) continue;
            if(dp[t] > dp[t-u] + 1){
                dp[t] = dp[t-u] + 1;
                copy(ans[t-u],ans[t-u]+3,ans[t]);
                ++ans[t][cac[u]];
            }
        }
    }
    int m;
    cin >> m;
    if(m % 10) return 0 * puts("-1");
    cout << ans[m/10][0] << ' ' << ans[m/10][1] << ' ' << ans[m/10][2] << '\n';
}