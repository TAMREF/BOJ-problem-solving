#include <cstdio>
#include <algorithm>
#include <functional>
int N,a[53], b[53];
int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",a+i);
    for(int i=0;i<N;i++) scanf("%d",b+i);
    std::sort(a,a+N,std::greater<int>());
    std::sort(b,b+N);
    long long S=0;
    for(int i=0;i<N;i++) S+=a[i]*b[i];
    printf("%lld\n",S);
    return 0;
}
