#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int prime[100];
pair<int, int> tmp;
priority_queue<pair<int, int> > plis;
int main()
{
    int N, K;
    scanf("%d %d",&K,&N);
    for(int i=0;i<K;i++) scanf("%d",&prime[i]);
    sort(prime,prime+K);
    for(int i=0;i<K;i++) plis.push({-prime[i], i});
    for(int i=1;i<N;i++)
    {
        tmp=plis.top();
        plis.pop();
        //printf("%d : %d\n",i,-tmp.first);
        for(int j=tmp.second;j<K;j++){
            long long q= (long long)(-tmp.first)*(long long)(prime[j]);
            if(q>=2147483648LL) break;
            plis.push({-q,j});
        }
    }
    tmp=plis.top();
    printf("%d\n",-tmp.first);
    return 0;
}
