#include <cstdio>
#include <unordered_map>
std::unordered_map<int,int> u;
int N, M, x;
int main()
{
    scanf("%d",&N);
    while(N--) scanf("%d",&x), ++u[x];
    scanf("%d",&M);
    while(M--) scanf("%d",&x), printf("%d ",u[x]);
}
