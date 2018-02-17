#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx = 1e6 + 5;

int n, q;

ll sum[2][mx], chk[2][mx]; //r : 0, c : 1
ll cnt[2], del[2];

int main(){
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        sum[0][i] = (ll)n * i + (ll)n * (n + 1) / 2;
        sum[1][i] = sum[0][i];
    }
    char ty;
    for(int p=0,i;p<q;p++){
        scanf("%*c%c %d",&ty, &i);
        if(ty=='C'){
            if(chk[1][i]){
                puts("0");
            }else{
                printf("%lld\n",sum[1][i]-del[1]-cnt[1]*i);
                chk[1][i] = 1;

                ++cnt[0];
                del[0] += i;
            }
        }else{
            if(chk[0][i]){
                puts("0");
            }else{
                printf("%lld\n",sum[0][i]-del[0]-cnt[0]*i);
                chk[0][i] = 1;

                ++cnt[1];
                del[1] += i;
            }
        }
    }
}