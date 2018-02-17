#include <cstdio>
inline int m(int x,int y,int z){return (x=(x<y?x:y))<z?x:z;}
const int X=2001, I=1e9;
int a[X],b[X],d[X][X],N,M,i,j,t;
int main(){
    scanf("%d%d",&N,&M);
    for(i=1;i<=N;--a[i],d[i++][0]=I) scanf("%d",&a[i]);
    for(i=1;i<=M;--b[i],d[0][i++]=I) scanf("%d",&b[i]);
    for(i=1;i<=N;i++) for(j=1;j<=M;j++) d[i][j]=m(d[i][j-1],d[i-1][j],d[i-1][j-1])+a[i]*b[j];
    printf("%d\n",d[N][M]);
}
