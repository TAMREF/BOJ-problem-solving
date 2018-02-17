#include <cstdio>
#define max(a,b) ((a)<(b)?(b):(a))
int a[1000000], M, N, l=1, m, h=1e9;
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++) scanf("%d",a+i);
    while(l<=h)
    {
        m = (l+h)>>1;
        long long T = 0;
        for(int i=0;i<N;i++) T+=(long long)max(0,a[i]-m);
        if(T>=M) l = m+1;
        else h = m-1;
    }
    printf("%d\n",l-1);
}
