#include <cstdio>
#include <set>
std::set<int> a;
int main()
{
    int x,N, M;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&x);
        a.insert(x);
    }
    scanf("%d",&M);
    while(M--)
    {
        scanf("%d",&x);
        printf("%d\n",a.find(x)!=a.end());
    }
}
