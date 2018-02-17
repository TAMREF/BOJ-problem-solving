#include <bits/stdc++.h>
using namespace std;
const int MAXN = 333;
int N, M, i, j, k;
int ans, S;
int x[MAXN], L[MAXN][MAXN][2], R[MAXN][MAXN][2];
void input(){
    scanf("%d%d",&N,&M);
    for(i=0;i<N;i++) scanf("%d",&x[i]);
    x[N++]=0;
    sort(x,x+N);
    S = (int)(lower_bound(x,x+N,0)-x);
}
void dp(){
    for(k=1;k<N;k++){
        for(i=0,j=0;j<N;j++){
            L[i][j][k&1]=R[i][j+1][~k&1]+k*(x[j+1]-x[i]);
            R[i][j][k&1]=R[i][j+1][~k&1]+k*(x[j+1]-x[j]);
        }
        for(i=1,j=N-1;i<N;i++){
            L[i][j][k&1]=L[i-1][j][~k&1]+k*(x[i]-x[i-1]);
            R[i][j][k&1]=L[i-1][j][~k&1]+k*(x[j]-x[i-1]);
        }
        for(i=1;i<N-1;i++){
            for(j=i;j<N-1;j++){
                L[i][j][k&1] = min(L[i-1][j][~k&1]+k*(x[i]-x[i-1]),R[i][j+1][~k&1]+k*(x[j+1]-x[i]));
                R[i][j][k&1] = min(L[i-1][j][~k&1]+k*(x[j]-x[i-1]),R[i][j+1][~k&1]+k*(x[j+1]-x[j]));
            }
        }
        ans = max(ans,k*M - L[S][S][k&1]);
    }
}
int main(){
    input();
    dp();
    printf("%d\n",ans);
}
