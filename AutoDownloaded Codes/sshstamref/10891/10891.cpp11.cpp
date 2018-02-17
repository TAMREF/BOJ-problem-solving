#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;
typedef vector<int>::reverse_iterator vri;
vector<int> e[100003], tam;
int col[100003];
bool cnt[100003];
void kill()
{
    puts("Not cactus");
    exit(0);
}
void dfs(int px, int x)
{
    tam.push_back(x);
    col[x]=1;
    for(auto &t : e[x])
    {
        if(t!=px){
        if(col[t]==1)
        {
            for(vri re=tam.rbegin();*re!=t;re++)
                {
                    if(cnt[*re]) kill();
                    ++cnt[*re];
                }
            if(cnt[t]) kill();
            ++cnt[t];
        }
        else if(!col[t]) dfs(x,t);
        }
    }
    col[x]=2;
    tam.pop_back();
}
int main()
{
    int N, M, a, b;
    scanf("%d %d",&N, &M);
    for(int i=0;i<M;i++)
    {
        scanf("%d %d",&a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(0,1);
    puts("Cactus");
    return 0;
}
