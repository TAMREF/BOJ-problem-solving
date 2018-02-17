#include <cstdio>
typedef long long ll;
ll dp[2][8005],S[8005];
int G, L, h;
void dnc_opt(int s, int e, int kmin, int kmax){
    if(s>e) return;
    int m=(s+e)>>1,ksol;
    dp[h][m]=1LL<<62;
    for(int k=kmin;k<=kmax&&k<m;k++){
        ll comp=dp[!h][k]+(S[m]-S[k])*(m-k);
        if(dp[h][m]>comp) dp[h][m]=comp, ksol=k;
    }
    dnc_opt(s,m-1,kmin,ksol);
    dnc_opt(m+1,e,ksol,kmax);
}
int main(){
    scanf("%d%d",&L,&G);
    for(int i=1;i<=L;i++) scanf("%lld",&S[i]),S[i]+=S[i-1],dp[0][i]=1LL<<60;
    for(int g=1;g<=G;g++) dnc_opt(1,L,0*(h=g&1),L);
    printf("%lld\n",dp[G&1][L]);
}
