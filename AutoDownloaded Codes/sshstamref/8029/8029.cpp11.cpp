#include <bits/stdc++.h>
using namespace std;

int d[755][755], psum[755][755];;
int n, r;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> r;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> d[n + i][n + j];
        }
    }
    for(int i = n + 1; i <= n + n + r; i++){
        for(int j = n + 1; j <= n + n + r; j++){
            psum[i][j] = d[i][j] + psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
        }
    }
    for(int i = n + 1; i <= n + n; i++){
        for(int j = n + 1;j <= n + n; j++){
            cout << psum[i+r][j+r] - psum[i-r-1][j+r] - psum[i+r][j-r-1] + psum[i-r-1][j-r-1] << ' ';
        }
        cout << '\n';
    }
}
