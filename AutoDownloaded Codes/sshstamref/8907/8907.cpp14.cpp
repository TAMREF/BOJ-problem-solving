#include <cstdio>
int b[1111], N, T,x, ans;
char q[1111];
int main()
{
    scanf("%d",&T);
    while(T--){
    scanf("%d",&N);
    for(int i=1;i<N;i++)
    {
        for(int j=0;j<N-i;j++)
        {
            scanf("%d",&x);
            b[i]+=x, b[i+j+1]+=x;
        }
    }
    ans = N*(N-1)*(N-2);
    for(int i=1;i<=N;i++) ans-=3*b[i]*(N-1-b[i]);
    printf("%d\n",ans/6);
    for(int i=1;i<=N;i++) b[i]=0;
    }
}