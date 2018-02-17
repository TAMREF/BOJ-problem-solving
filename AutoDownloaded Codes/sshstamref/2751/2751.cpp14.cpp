#include <cstdio>
#include <algorithm>
int a[1111111];
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",a+i);
    std::sort(a,a+N);
    for(int i=0;i<N;i++) printf("%d\n",a[i]);
}