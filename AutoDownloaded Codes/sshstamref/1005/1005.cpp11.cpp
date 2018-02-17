#include <cstdio>
#include <vector>
#include <algorithm>
int W, N,M, x, y, tc, D[1003], p[1003], dt[1003],  disctime[1003];
bool col[1003];
std::vector<int> parent[1003];
std::vector<int> child[1003];

int getdt(int s)
{
    if(!parent[s].size())
    {
        dt[s]=D[s];
        return D[s];
    }
    int mx=0;
    for(auto &r : parent[s])
    {
        mx=std::max(mx, (dt[r])?(dt[r]):(getdt(r)));
    }
    dt[s]=mx+D[s];
    return dt[s];
}
int main()
{
    //step 1 - initiation
    scanf("%d",&tc);
    for(int m=0;m<tc;m++)
    {
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&D[i]);
        p[i]=i;
    }
    for(int i=0;i<M;i++)
    {
        scanf("%d %d",&x, &y);
        child[x].push_back(y);
        parent[y].push_back(x);
    }
    scanf("%d",&W);
    //step 2- dynamic Rodong
    printf("%d\n",getdt(W));
    for(int i=1;i<=N;i++)
    {
        parent[i].clear();
        child[i].clear();
        disctime[i]=dt[i]=col[i]=0;
    }
    }
}
