#include <cstdio>
int d[4][32769];
int main(){
    for(int j=1;j*j<32768;j++){
        d[0][j*j]=1;
        for(int k=1;k+j*j<=32768;k++){
            for(int l=0;l<3;l++) d[l+1][k+j*j]+=d[l][k];
        }
    }
    for(;;){
        int n;
        scanf("%d",&n); if(!n) return 0;
        printf("%d\n",d[0][n]+d[1][n]+d[2][n]+d[3][n]);
    }
}