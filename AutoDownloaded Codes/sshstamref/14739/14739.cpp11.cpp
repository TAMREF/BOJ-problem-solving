#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5+5;
int incr[mx], decr[mx], dp[mx], a[mx], query[mx], num[mx];
int n, q;
void init(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    incr[n-1] = decr[n-1] = dp[n-1] = 1;
    for(int i=n-1;i--;){
        if(a[i]<=a[i+1]){
            incr[i] = incr[i+1] + 1;
            decr[i] = 1;
            dp[i] = incr[i];
        }else{
            incr[i] = 1;
            decr[i] = decr[i+1] + 1;
            dp[i] = decr[i];
        }
    }
    for(int m = 2;m<=n;m++){
        for(int p = 0;p<n;++num[m]){
            if(dp[p] >= m){
                p += dp[p];
            }
            else if(p+dp[p]<n){
                query[m] += (p+m<=n?m-dp[p]:n-p-dp[p]);
                p+=m;
            }else{
                p = n;
            }
        }
    }
}
void work(){
    cin>>q;
    for(int r=0;q--;){
        cin>>r;
        cout<<num[r]<<' '<<query[r]<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    init();
    work();
}
