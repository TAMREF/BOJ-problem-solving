#include <cstdio>
#include <unordered_set>
std::unordered_set<int> u;
int N, M, x;
int main()
{

    scanf("%d",&N);
    while(N--) scanf("%d",&x), u.insert(x);
    scanf("%d",&M);
    while(M--) scanf("%d",&x), printf("%d ",u.find(x)!=u.end());
}
