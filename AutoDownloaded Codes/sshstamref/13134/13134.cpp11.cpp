#include <bits/stdc++.h>
using namespace std;
int cnt[19683], N;
int mn=1e6, mx=0;
int pow3[9]={1,3,9,27,81,243,729,2187,6561};
int mod3[9];
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int x=0,y;
        for(int j=0;j<9;j++){
            scanf("%d",&y);
            x=3*x+(y-1);
        }
        ++cnt[x];
    }
    for(int p=0;p<19683;p++){
        int ans=0;
        for(int i=0;i<9;i++) mod3[i]=(p/pow3[i])%3;
        for(int s=0;s<512;s++){
            int bm=0;
            for(int i=0;i<9;i++){
                int fi=(mod3[i]?0:1), se=3-fi-mod3[i];
                bm=3*bm+((s>>i)&1?se:fi);
            }
            ans+=cnt[bm];
        }
        mn=min(mn,ans);
        mx=max(mx,ans);
    }
    printf("%d %d\n",mn,mx);
}