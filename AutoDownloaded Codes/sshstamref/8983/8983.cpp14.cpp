#include <cstdio>
#include <algorithm>
int a[100003], x[100003], y[100003], M, N, L, cnt;
int main()
{
    scanf("%d %d %d",&M,&N,&L);
    for(int i=0;i<M;i++) scanf("%d",&a[i]);
    std::sort(a,a+M);
    for(int i=0;i<N;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
        int low=0, high=M-1, mid;
        if(x[i]>a[M-1])
        {
            if(x[i]-a[M-1]+y[i]<=L) ++cnt;
            continue;
        }
        if(x[i]<a[0])
        {
            if(a[0]-x[i]+y[i]<=L) ++cnt;
            continue;
        }
        while((high-low)>1)
        {
            mid=(high+low)/2;
            if(a[mid]>=x[i]) high=mid;
            else low=mid;
        }
        if((x[i]-a[low]+y[i]<=L)||(-x[i]+a[high]+y[i]<=L)) ++cnt;
    }
    printf("%d\n",cnt);
}
