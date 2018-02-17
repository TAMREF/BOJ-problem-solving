#include <bits/stdc++.h>
int N, M;
long long T[100010];
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++) scanf("%lld",&T[i]);
    long long l = 1, h = 1e18, m;
    while(l<h)
    {
        m = (l+h)>>1;
        long long ans = 0;
        for(int i=0;i<N;i++) ans+=m/T[i];
        if(ans>=M) h = m;
        else l = m+1;
    }
    printf("%lld\n",h);
}
