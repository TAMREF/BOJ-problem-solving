#include <bits/stdc++.h>
using namespace std;

int E[505][505];
int n, k;

int main(){
    cin >> n >> k;
    for(int i=1;i<=n;i++) E[i][1] = i;
    for(int i=1;i<=n;i++){
        for(int j=2;j<=k;j++){
            E[i][j] = INT_MAX;
            for(int s=1;s<=i;s++){
                //printf("i j s = %d %d %d, val = 1 + max(E[%d][%d]=%d, E[%d][%d]=%d)\n",i,j,s,min(j,i-s),j,E[i-s][min(j,i-s)],s-1,min(j-1,s-1),E[s-1][min(j-1,s-1)]);
                E[i][j] = min(E[i][j], 1 + max(E[i-s][j], E[s-1][j-1]));
            }
            //printf("E[%d][%d] = %d\n",i,j,E[i][j]);
        }
    }
    cout << E[n][k] << endl;
}
