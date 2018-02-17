#include <cstdio>
int i,j,k, N, M, K, a[111][111], b[111][111], c[111][111];
int main()
{
    scanf("%d%d",&N,&M);
    for(i=0;i<N;i++)
        for(j=0;j<M;j++) scanf("%d",a[i]+j);
    scanf("%d%d",&M,&K);
    for(i=0;i<M;i++)
        for(j=0;j<K;j++) scanf("%d",b[i]+j);
    for(i=0;i<N;i++)
        for(j=0;j<K;j++)
            for(k=0;k<M;k++) c[i][j]+=a[i][k]*b[k][j];
    for(i=0;i<N;i++,puts(""))
        for(j=0;j<K;printf("%d ",c[i][j++]));
}
