#include <cstdio>
#include <stack>
using namespace std;
struct yee{int num, up, same;};
stack<yee> tam;
int N, x;
int main()
{
    scanf("%d",&N);
    long long ans=0;
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&x);
        while(!tam.empty() && tam.top().num<x)
        {
            ans+=tam.top().same;
            tam.pop();
        }
        if(tam.empty()) tam.push({x,0,1});
        else
        {
            if(tam.top().num==x)
            {
                yee tmp=tam.top();
                ans+=tmp.same+tmp.up;
                tam.pop();
                ++tmp.same;
                tam.push(tmp);
            }
            else
            {
                ++ans;
                tam.push({x,1,1});
            }
        }
    }
    printf("%lld\n",ans);
}
