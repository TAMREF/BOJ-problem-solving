#include <cstdio>
#include <algorithm>
using namespace std;
int mpath[503][503], triag[503][503];

int main()
{
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=i;j++)
            scanf("%d",&triag[i][j]);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=i;j++)
            mpath[i][j]=max(mpath[i-1][j-1],mpath[i-1][j])+triag[i][j];
    int mx=0;
    for(int i=1;i<=N;i++)
        mx=max(mx,mpath[N][i]);
    printf("%d\n",mx);
}