#include <cstdio>
#include <climits>
#include <unordered_map>
std::unordered_map<long long,int> tam;
long long a=LLONG_MAX, N, x;
int main()
{
    scanf("%d",&N);
    while(N--)
    {
        scanf("%lld",&x);
        if(++tam[x]>tam[a]) a=x;
        if(tam[x]==tam[a] && x<a) a=x;
        //printf("%lld %d\n",a,tam[a]);
    }
    printf("%lld\n",a);
    return 0;
}
