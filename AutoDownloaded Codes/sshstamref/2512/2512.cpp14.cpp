#include <cstdio>
#include <algorithm>
using namespace std;
int bud, call[111111], tot, P=-1;
int main()
{
    int N; scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",call+i), tot+=call[i];
    for(int i=0;i<N;i++) P=max(P,call[i]);
    scanf("%d",&bud);
    int low = 2, high = 100001, mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        long long X=0;
        for(int i=0;i<N;i++) X+=min(call[i],mid);
        if(X<=bud && P>=mid) low=mid+1;
        else high=mid-1;
    }
    printf("%d\n",high);
}
