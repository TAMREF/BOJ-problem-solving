#include <cstdio>
int S, X, m=1e7, N, q;
int main()
{
    for(scanf("%d",&N);N--;scanf("%d",&q),S+=q,X^=q,m=m<q?m:q);
    printf("%d\n",X?0:S-m);
}