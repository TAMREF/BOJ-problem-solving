#include <cstdio>
int arg[333][333], psum[333][333];
int K, i, j, x, y, N, M;
int main()
{
    scanf("%d%d",&N,&M);
    for(int p=1;p<=N;p++) for(int q=1;q<=M;q++) scanf("%d",&arg[p][q]);
    for(int p=1;p<=N;p++)
    {
        for(int q=1;q<=M;q++)
        {
            psum[p][q]=psum[p-1][q]+psum[p][q-1]+arg[p][q]-psum[p-1][q-1];
        }
    }
    scanf("%d",&K);
    while(K--)
    {
        scanf("%d%d%d%d",&i,&j,&x,&y);
        printf("%d\n",psum[x][y]-psum[i-1][y]-psum[x][j-1]+psum[i-1][j-1]);
    }
}
