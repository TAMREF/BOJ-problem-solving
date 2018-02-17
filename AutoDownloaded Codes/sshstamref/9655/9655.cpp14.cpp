#include <cstdio>
bool firstwin[1003];
int N;
bool build()
{
    firstwin[1]=firstwin[3]=true;
    for(int i=4;i<=N;i++) firstwin[i]=!(firstwin[i-1]&&firstwin[i-3]);
    return firstwin[N];
}
int main()
{
    scanf("%d",&N);
    build()? puts("SK") : puts("CY");
}
