#include <cstdio>
#include <algorithm>
using namespace std;
int stair[2][303], point[303];
int main()
{
    int N; scanf("%d",&N);
    for(int i=1;i<=N;i++) scanf("%d",&point[i]);
    stair[0][1]=point[1]; stair[0][2]=point[2]; stair[1][2]=point[1]+point[2];
    for(int i=3;i<=N;i++)
    {
        if(stair[0][i-2]||stair[1][i-2]) stair[0][i]=point[i]+max(stair[0][i-2],stair[1][i-2]);
        if(stair[0][i-1]) stair[1][i]=stair[0][i-1]+point[i];
    }
    printf("%d\n",max(stair[0][N],stair[1][N]));
}
