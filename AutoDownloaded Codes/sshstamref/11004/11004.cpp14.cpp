#include <cstdio>
#include <algorithm>
int a[5000000], N, K;
int main()
{
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++) scanf("%d",a+i);
    std::sort(a,a+N);
    printf("%d\n",a[K-1]);
}
