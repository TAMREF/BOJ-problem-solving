#include <bits/stdc++.h>
using namespace std;

const int mx = 5005;

int psum[mx], opt[mx][mx], dp[mx][mx];
int n;

void init(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>psum[i];
        psum[i] += psum[i-1];
    }
    for(int i=1;i<=n;i++){
        opt[i][i] = i;
        dp[i][i] = 0LL;
    }
}

void dp_fill(){
    for(int d = 1; d < n; d++){
        for(int i = 1; i + d <= n; i++){
            int j = i + d;
            dp[i][j] = INT_MAX;

            for(int k = opt[i][j-1] ; k <= opt[i+1][j] ; k++){
                if( dp[i][k] + dp[k+1][j] + psum[j] - psum[i-1] < dp[i][j] ){
                    dp[i][j] = dp[i][k] + dp[k+1][j] + psum[j] - psum[i-1];
                    opt[i][j] = k;
                }
            }
        }
    }

    cout << dp[1][n] << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    for(cin>>t;t--;){
        init();
        dp_fill();
    }
}
