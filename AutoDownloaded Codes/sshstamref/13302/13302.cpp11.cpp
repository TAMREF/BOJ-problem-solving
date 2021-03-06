#include <bits/stdc++.h>
using namespace std;
const int mx=108, inf=1e9;
int dp[mx][mx], mark[mx], N, M;
void input(){
    for(int a=scanf("%d%d",&N,&M);M--;){
        scanf("%d",&a);
        mark[a]=1;
    }
    for(int i=0;i<mx;i++) for(int j=0;j<mx;j++) dp[i][j]=inf;
}
//dp[i][j] : i일째를 보내야 하는데 쿠폰이 j개 남은 상황에서의 최소 비용
void pro(){
    dp[1][0]=0;
    for(int i=1;i<=N;i++){
        if(mark[i]) for(int j=0;j<=i;j++) dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
        else{
            for(int j=0;j<=i;j++){
                dp[i+1][j]=min(dp[i+1][j],dp[i][j]+10);
                for(int t=1;t<=3;t++)
                    dp[i+t][j+1]=min(dp[i+t][j+1],dp[i][j]+25);
                for(int t=1;t<=5;t++)
                    dp[i+t][j+2]=min(dp[i+t][j+2],dp[i][j]+37);
                if(j>2) dp[i+1][j-3]=min(dp[i+1][j-3],dp[i][j]);
            }
        }
    }
    int val=inf;
    /*
    for(int i=1;i<=N+5;i++,puts("")){
        if(mark[i]) puts("----------------------");
        for(int j=0;j<=i;j++) printf("%d ",dp[i][j]==inf?-1:dp[i][j]);
        if(mark[i]) fputs("\n----------------------",stdout);
    }*/
    for(int i=N+1;i<=N+5;i++)
        for(int j=0;j<=i;j++)
            val=min(val,dp[i][j]);
    printf("%d\n",val*1000);
}
int main(){
    input();
    pro();
}