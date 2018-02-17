#include <bits/stdc++.h>
using namespace std;
char ioi[1000005];
int main(){
    int n,m,lp,rp,cnt=0;
    scanf("%d\n%d\n",&n,&m);
    scanf("%s",ioi);
    for(lp=rp=0;rp<=m;rp++){
        if(rp==lp){
            if(ioi[rp]=='O') ++lp;
        }else{
            if(rp-lp==2*n+1){
                ++cnt; lp+=2;
                //printf("found on [%d,%d)\n",lp-2,rp);
            }
            if(ioi[rp-1]==ioi[rp]) lp=(ioi[rp]=='I'?rp:rp+1);
        }
    }
    printf("%d\n",cnt);
}