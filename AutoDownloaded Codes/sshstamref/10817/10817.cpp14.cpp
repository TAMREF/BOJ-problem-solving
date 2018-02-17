#include <cstdio>
#include <algorithm>
int a[3];
int main()
{
    for(int i=0;i<3;i++) scanf("%d",a+i);
    std::sort(a,a+3);
    printf("%d\n",a[1]);
}