#include <bits/stdc++.h>
using namespace std;
double f[2][1005][2010];
int main(){
    int p,n;
    double h,t;
    for(scanf("%d",&p);p--;){
        scanf("%d%lf%lf",&n,&t,&h);
        for(int i=0;i<=n;i++) for(int j=0;j<=2*n;j++) f[0][i][j+1]=(double)(i>=j-n?i:0.0);
        //for(int i=0;i<=n;i++) for(int j=0;j<=2*n;j++) f[1][i][j+1]=0.0;
        for(int k=1;k<=n;k++){
            for(int m=0;m<=n-k;m++){
                for(int l=k;l<=n+m;l++){
                    f[k&1][m][l+1]=h*f[~k&1][max(m,l+1-n)][l+2]+(1-h-t)*f[~k&1][m][l+1]+t*f[~k&1][m][l];
                }
            }
            //for(int m=0;m<=n-k;m++,puts("")) for(int l=0;l<=2*n;l++) printf("f[%d][%d][%d]=%f\n",k,m,l,f[k&1][m][l]);
        }
        printf("%.4f\n",f[n&1][0][n+1]);
    }
}