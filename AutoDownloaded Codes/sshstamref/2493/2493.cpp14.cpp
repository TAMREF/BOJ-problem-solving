#include <cstdio>
#include <stack>
using namespace std;
stack<int> num, height;
int main()
{
    int N, x, y;
    scanf("%d",&N);
    scanf("%d",&x);
    printf("0 ");
    num.push(1);
    height.push(x);
    for(int i=2;i<=N;i++)
    {
        scanf("%d",&x);
        while(!height.empty() && x>=height.top()) height.pop(), num.pop();
        printf("%d ",(num.empty())?(0):(num.top()));
        height.push(x); num.push(i);
    }
    return 0;
}
