#include <cstdio>
long long ans, N, a[22], S;
int main()
{
    scanf("%lld %lld",&N,&S);
    for(int i=0;i<N;i++) scanf("%lld",a+i);
    for(int msk=1;msk<1<<N;msk++)
    {
        int sub=0;
        for(int t=0;t<N;t++) if(1<<t & msk) sub+=a[t];
        if(sub==S) ++ans;
    }
    printf("%lld\n",ans);
}
