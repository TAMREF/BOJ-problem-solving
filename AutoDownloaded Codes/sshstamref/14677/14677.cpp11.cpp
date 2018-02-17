#include <bits/stdc++.h>
using namespace std;
int n,dp[1505][1505];
int m[255];
char buf[1505];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    m['B']=0, m['L']=1, m['D']=2;
    for(int i=0;i<3*n;i++) cin>>buf[i];
    for(int d=0,e,x;d<3*n;d++){
        for(int s=0;s+d<3*n;s++){
            e=s+d; x=((s-e-1)%3+3)%3;
            if(m[buf[s]]==x) dp[s][e]=dp[s+1][e]+1;
            if(m[buf[e]]==x) dp[s][e]=max(dp[s][e],dp[s][e-1]+1);
        }
    }
    //for(int i=0;i<3*n;i++) for(int j=0;j<3*n;j++) cout<<dp[i][j]<<" \n"[j==3*n-1];
    cout<<dp[0][3*n-1]<<endl;
}