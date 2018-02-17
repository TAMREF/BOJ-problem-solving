#include <cstdio>
#include <algorithm>
int tau, t[55], i;
int main()
{
    for(scanf("%d",&tau);i<tau;i++) scanf("%d",t+i);
    std::sort(t,t+tau);
    printf("%d\n",t[0]*t[tau-1]);
}
