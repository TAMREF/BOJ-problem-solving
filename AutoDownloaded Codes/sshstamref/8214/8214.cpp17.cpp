#include <bits/stdc++.h>
using namespace std;

const int mx = 3005;

bool adj[mx][mx], chk[mx];
int n, m;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int a, b;m--;){
        cin >> a >> b;
        adj[a][b] = 1;
    }
    int coin=0;
    for(int i=1;i<=n;i++){
        if(chk[i]) continue;
        for(int j=i+1;j<=n;j++){
            if(coin >= 2 * n / 3) goto FIN;
            if(!chk[i] && !chk[j] && !adj[i][j]){
                chk[i] = chk[j] = 1;
                coin += 2;
                break;
            }
        }
    }
    FIN:
    for(int i=1,cnt=0;i<=n && cnt < n / 3; i++){
        if(!chk[i]){
            cout << i << ' ';
            ++cnt;
        }
    }
    cout << '\n';
    return 0;
}