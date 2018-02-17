#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k,T,S[104][104]={},B[104][104]={};
    memset(S,0,sizeof(S));
    memset(B,0,sizeof(B));
    S[1][0]=B[1][0]=1;
    for(int i=2;i<=102;i++){
        for(int j=0;j<i;j++){
            S[i][j]=S[i-1][j-1]+B[i-1][j];
            B[i][j]=B[i-1][j]+S[i-1][j];
        }
    }
    for(scanf("%d",&T);T--;){
        scanf("%d%d",&n,&k);
        if(n<2||k>=n){
            puts("0");
            continue;
        }
        printf("%d\n",S[n][k]+B[n][k]);
    }
}