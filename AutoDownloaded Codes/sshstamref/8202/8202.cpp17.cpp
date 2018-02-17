#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx = 5005;

int deg[mx], n, cnt[mx], sdg[mx], m;
vector<int> G[mx];

unsigned int C[mx][mx];

int input(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> deg[i];
        m += deg[i];
        ++cnt[deg[i]];
        for(int j=0,y;j<deg[i];j++){
            cin >> y;
        }
    }
    m /= 2;
    copy(deg,deg+n,sdg);
    sort(sdg,sdg+n,greater<int>());
    return 1;
}

void qkrghdqls1(){
    int tdg = 0;
    long long ans = 0;
    for(int i=0,curr=0;i<n-1;i++){
        //printf("sdg[%d] = %d, cnt[%d] = %d\n",i,sdg[i],sdg[i],cnt[sdg[i]]);
        tdg += sdg[i] - i;
        if(sdg[curr] != sdg[i]){
            curr = i;
        }
        if(tdg == m){
            ans += C[cnt[sdg[i]]][i-curr+1];
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=0;i<mx;i++) C[i][0] = 1;
    for(int i=1;i<mx;i++){
        for(int j=1;j<=i;j++){
            C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
    }
    if(input()) qkrghdqls1();
}