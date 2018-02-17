#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int d[101][101];
int main(){
    int N, M, x, y, z; scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) d[i][j]=(i==j?0:INF);
    while(M--){
        scanf("%d%d%d",&x,&y,&z);
        d[x-1][y-1]=min(d[x-1][y-1],z);
    }
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) for(int k=0;k<N;k++) d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
    for(int i=0;i<N;i++,puts("")) for(int j=0;j<N;j++) printf("%d ",d[i][j]<INF?d[i][j]:0);
}
