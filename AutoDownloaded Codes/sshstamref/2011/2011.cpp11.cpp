#include <bits/stdc++.h>
using namespace std;
const int mod=1e6;
char s[5005];
int n;
int dp[5005];
void input(){
    scanf("%s",s); n=strlen(s);
    for(int i=0;i<n;i++) s[i]&=15;
    //for(int i=0;i<n;i++) printf("%d ",s[i]); puts("");
    s[n]=27;
}
void pro(){
    dp[0]=1;
    for(int i=0;i<n;i++){
        if(!s[i]) continue;
        (dp[i+1]+=dp[i])%=mod;
        if(10*s[i]+s[i+1]<27) (dp[i+2]+=dp[i])%=mod;
    }
    printf("%d\n",dp[n]%mod);
}
int main(){
    input();
    pro();
}