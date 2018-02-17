#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx=300;
ll x,y,p,q;
ll eu[mx], dp[2*mx];
int E;
void workgcd(ll u, ll v){
    eu[E++]=v;
    if(!v) return;
    workgcd(v,u%v);
}
int main(){
    int T;
    for(scanf("%d",&T);T--;){
        scanf("%lld%lld%lld%lld",&x,&y,&p,&q);
        E=0;
        fill(dp,dp+2*mx,0);
        eu[E++]=max(x,y);
        workgcd(max(x,y),min(x,y));
        for(int i=E-3;i>=0;i--){
            if((double)(p+dp[2*i+2]-dp[2*i+3])/q<eu[i]/eu[i+1]) dp[2*i]=dp[2*i+2]+p;
            else dp[2*i]=dp[2*i+3]+q*(eu[i]/eu[i+1]);
            if((double)(p+dp[2*i]-dp[2*i+2])/q<eu[i]/eu[i+1]) dp[2*i+1]=dp[2*i]+p;
            else dp[2*i+1]=dp[2*i+2]+q*(eu[i]/eu[i+1]);
        }
        printf("%lld\n",x>=y?dp[0]:dp[1]);
    }
}