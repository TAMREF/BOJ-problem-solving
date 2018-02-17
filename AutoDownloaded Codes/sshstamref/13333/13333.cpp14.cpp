#include <cstdio>
int N, a[1005], t, m, p;
int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    for(int i=0;i<=N;i++)
    {
        t=m=p=0;
        for(int j=0;j<N;j++)
        {
            if(a[j]>i) ++t;
            else if(a[j]==i) ++m;
            else ++p;
        }
        if(t<=i && t+m>=i)
        {
            printf("%d\n",i);
            return 0;
        }
    }
}