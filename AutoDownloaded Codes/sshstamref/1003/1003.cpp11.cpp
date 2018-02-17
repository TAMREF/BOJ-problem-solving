#include <cstdio>
long long numz[50], numo[50];
int main()
{
    numz[0]=1;
    numo[1]=1;
    int C, N;
    scanf("%d\n",&C);
    for(int i=2;i<=50;i++)
    {
        numz[i]=numz[i-1]+numz[i-2];
        numo[i]=numo[i-1]+numo[i-2];
    }
    for(int i=0;i<C;i++)
    {
    scanf("%d",&N);
    printf("%lld %lld\n",numz[N],numo[N]);
    }
}
