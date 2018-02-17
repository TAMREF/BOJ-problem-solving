#include <cstdio>
#include <vector>

using namespace std;
vector<int> que;
int rep[1000003];

int f(int x)
{
    if(rep[x]==x) return x;
    rep[x]=f(rep[x]);
    return rep[x];
}

void c(int x, int y)
{
    x=f(x); y=f(y);
    if(x>y) rep[x]=y;
    else rep[y]=x;
}

bool un(int x, int y)
{
    return f(x)==f(y);
}

int main()
{
    int N, code, a, b, m;
    scanf("%d %d",&N,&m);
    for(int i=0;i<=N;i++) rep[i]=i;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&code,&a, &b);
        if(code)
            que.push_back(un(a,b));
        else
            c(a,b);
    }
    for(auto &x : que)
    {
        if(x) puts("YES");
        else puts("NO");
    }
    return 0;
}
