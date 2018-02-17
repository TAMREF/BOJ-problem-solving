#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;
int tsp[17][65537], N, i, j, k, bit, rod, tmp, W[17][17];
void input(){
    scanf("%d",&N);
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            scanf("%d",&W[i][j]);
            W[i][j]=W[i][j]?W[i][j]:INF;
        }
    }
    for(i=0;i<N;i++)
        for(bit=0;bit<(1<<N);bit++) tsp[i][bit]=INF;
    tsp[0][0]=0;
}
void travel(){
    for(bit=1;bit<(1<<N);bit++){
        for(i=0;i<N;i++){
            //printf("before : i=%d, bit=%d, tsp[i][bit]=%d\n",i,bit,tsp[i][bit]);
            for(j=0;j<N;j++){
                if((bit&(1<<j))==0) continue;
                rod = bit-(1<<j);
                tsp[i][bit]=min(tsp[i][bit],tsp[j][rod]+W[j][i]);
                //printf("modified : i=%d, j=%d, bit=%d, tsp[i][bit]=%d\n",i,j,bit,tsp[i][bit]);
            }
        }
    }
}
void debug(){
    for(bit=0;bit<(1<<N);bit++){
        printf("tsp for %02d : ",bit);
        for(i=0;i<N;i++) printf("%02d ",tsp[i][bit]!=INF?tsp[i][bit]:-1);
        puts("");
    }
    for(i=0;i<N;i++){
        for(j=0;j<N;j++) printf("%02d ",W[i][j]!=INF?W[i][j]:-1);
        puts("");
    }
}
int main(){
    input();
    travel();
    printf("%d\n",tsp[0][(1<<N)-1]);
    //debug();
}
