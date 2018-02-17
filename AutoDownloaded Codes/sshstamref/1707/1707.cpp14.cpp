#include <cstdio>
#include <vector>
using namespace std;
vector<int> edge[20003];
bool mark[20003];
int rep[20003];
bool dfs(int x, int r)
{
    rep[x]=r;
    mark[x]=true;
    bool ch=true;
    for(int &t : edge[x])
    {
        if(rep[t]==r)
        {
            //printf("damn thing happened in %d %d, %d\n",x,t,r);
            return false;
        }
        else if(rep[t]==0)
        {
            ch=(ch&&dfs(t,3-r));
        }
    }
    return ch;
}
int main()
{
    int K, V, E, a, b;
    scanf("%d",&K);
    for(int tc=1;tc<=K;tc++)
    {
        scanf("%d %d",&V,&E);
        for(int i=1;i<=V;i++) {rep[i]=mark[i]=0; edge[i].clear();}
        for(int d=0;d<E;d++)
        {
            scanf("%d %d",&a,&b);
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        bool t=true;
        for(int i=1;i<=V;i++)
        {
            if(!mark[i])
            {
                t= t&&dfs(i,1);
            }
        }
        (t)?(puts("YES")):(puts("NO"));
    }
    return 0;
}
