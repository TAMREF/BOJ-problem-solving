#include <bits/stdc++.h>
using namespace std;

const int mx = 3005;

bool dp[mx][mx][2][2];
int num[mx], Ksor[mx];

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> num[i];
        num[i] &= 1;
        Ksor[i+1] = Ksor[i] ^ num[i];
    }
    for(int i=0; i <= n; i++)
        dp[i][i][0][1] = 1;
    for(int len = 1; len <= n; len++) {
        for(int i=0,j; i<n; i++) {
            j = i + len;
            if(j > n)
                break;
            for(int b = 0; b < 2; b++) {
                for(int c = 0; c < 2; c++) {
                    if(b ^ c == Ksor[j]^Ksor[i]) continue;
                    dp[i][j][b][c] |= !(dp[i+1][j][c][b^num[i]] && dp[i][j-1][c][b^num[j-1]]);
                    if(len >= 2) {
                        dp[i][j][b][c] |= !(dp[i+2][j][c][b^num[i]^num[i+1]] && dp[i][j-2][c][b^num[j-1]^num[j-2]]);
                    }
                    //printf("lower dps\n");
                    //printf("L1 : %d, L2 : %d, R1 : %d, R2 : %d\n",dp[i+1][j][c][b^num[i]],dp[i+2][j][c][b^num[i]^num[i+1]],dp[i][j-1][c][b^num[j-1]],dp[i][j-2][c][b^num[j-1]^num[j-2]]);
                    //printf("dp[%d][%d][%d][%d] = %d\n",i,j,b,c,dp[i][j][b][c]);
                }
            }
        }
    }
    cout << (dp[0][n][0][0]?"Yes":"No") << endl;
}