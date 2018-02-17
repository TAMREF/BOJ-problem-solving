#include <cstdio>
int main()
{
    int X, cnt=0;
    scanf("%d",&X);
    for(int i=0;i<=6;i++)
    {
        if(X&(1<<i)) ++cnt;
    }
    printf("%d\n",cnt);
    return 0;
}