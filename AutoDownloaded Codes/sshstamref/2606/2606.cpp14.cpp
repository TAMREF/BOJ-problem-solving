#include <cstdio>
#include <vector>
using namespace std;
vector<int> cn[103];
bool vis[103];
int cnt, v, e, a, b;
void dfs(int a)
{
    for(auto &t : cn[a])
    {
        if((!vis[t])&&t>1)
        {
            ++cnt;
            vis[t]=1;
            dfs(t);
        }
    }
}
int main()
{
    scanf("%d",&v);
    for(scanf("%d",&e);e;--e)
    {
        scanf("%d %d",&a,&b);
        cn[a].push_back(b);
        cn[b].push_back(a);
    }
    dfs(1);
    printf("%d\n",cnt);
    return 0;
}
