#include <cstdio>
#include <algorithm>
int N, C, x[200005];
int main()
{
    scanf("%d%d",&N,&C);
    for(int i=0;i<N;i++) scanf("%d",x+i);
    std::sort(x,x+N);
    int l = 1, m, h = 2e9+1;
    while(l<=h)
    {
        m=(l+h)>>1;
        int cnt = 1, cur = 0;
        for(int i=1;i<N;i++)
        {
            if((long long)m+x[cur]<=x[i])
            {
                cur = i;
                ++cnt;
            }
        }
        if(cnt<C) h = m-1;
        else  l = m+1;
    }
    printf("%d\n",l-1);
}
