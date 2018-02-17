#include <cstdio>
int D[11]={0,1,2,4};
int T, N;
int main()
{
    for(int i=4;i<11;i++) D[i]=D[i-1]+D[i-2]+D[i-3];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        printf("%d\n",D[N]);
    }
}
