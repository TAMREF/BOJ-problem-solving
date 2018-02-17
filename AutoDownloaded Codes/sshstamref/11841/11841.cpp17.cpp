#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx = 200005;

int dt[mx], ft[mx], clk;
int ord[mx], num;
int n, m;
int mem[mx];
int dp[mx][505];

vector<int> Child[mx];

void dfs(int x){
    if(Child[x].empty()) ++clk;
    dt[x] = clk;
    for(int &u : Child[x]){
        dfs(u);
    }
    ft[x] = clk;
    ord[num++] = x;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m;

    int rt;

    for(int i=1,p;i<=n;i++){
        cin >> p >> mem[i];
        if(p) Child[p].push_back(i);
        else rt = i;
    }

    dfs(rt);

    for(int i=0;i<n;i++){
        int u = ord[i];
        int l = dt[u], r = ft[u];

        for(int j = 1; j <= m; j++) dp[r][j] = max( dp[r-1][j], dp[r][j] );
        for(int j = 1; j <= m && j <= l; j++) dp[r][j] = max( dp[l-1][j-1] + mem[u], dp[r][j]);
    }

    int ans = 0;

    for(int i=1;i<=clk;i++) ans = max(dp[i][m], ans);

    cout << ans << endl;
    /*
    for(int i=1;i<=clk;i++){
        printf("Clock = %d : ",i);
        for(int j=0;j<=m;j++){
            printf("%d ",dp[i][j]);
        }
        puts("");
    }
    */
}