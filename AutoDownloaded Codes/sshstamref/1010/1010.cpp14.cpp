#include <cstdio>
long long dp[33][33];
int T,m,n;
int main()
{
    for(int i=0;i<30;i++) dp[i][0]=1;
    for(int i=1;i<30;i++)
        for(int j=1;j<=i;j++) dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        printf("%lld\n",dp[m][n]);
    }
}
