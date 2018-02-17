#include <cstdio>
bool firstwin[1003];
int N;
bool build()
{
    firstwin[1]=firstwin[3]=firstwin[4]=true;
    for(int i=5;i<=N;i++) firstwin[i]=!(firstwin[i-1]&&firstwin[i-3]&&firstwin[i-4]);
    return firstwin[N];
}
int main()
{
    scanf("%d",&N);
    build()? puts("SK") : puts("CY");
}