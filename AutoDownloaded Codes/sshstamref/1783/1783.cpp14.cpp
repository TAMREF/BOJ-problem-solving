#include <cstdio>
int N, M;
int main()
{
    scanf("%d%d",&N,&M);
    if(N>=3)
    {
        if(M>=7) printf("%d\n",M-2);
        else if(M>=4) puts("4");
        else if(M>=3) puts("3");
        else printf("%d\n",M/2+1);
    }
    else if(N==2)
    {
        if(M<3) puts("1");
        else if(M<5) puts("2");
        else if(M<7) puts("3");
        else puts("4");
    }
    else puts("1");
}
