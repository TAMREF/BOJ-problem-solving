#include <cstdio>
#include <algorithm>

using namespace std;
int cr[1003], cg[1003], cb[1003];
long long R[1003], G[1003], B[1003];

int main()
{
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
    scanf("%d %d %d",&cr[i], &cg[i], &cb[i]);
    }
    R[1]=cr[1]; G[1]=cg[1]; B[1]=cb[1];
    for(int i=2;i<=N;i++)
    {
        R[i]=min(G[i-1],B[i-1])+cr[i];
        G[i]=min(R[i-1],B[i-1])+cg[i];
        B[i]=min(R[i-1],G[i-1])+cb[i];
    }
    printf("%lld\n",min(R[N],min(B[N],G[N])));
    return 0;
}
