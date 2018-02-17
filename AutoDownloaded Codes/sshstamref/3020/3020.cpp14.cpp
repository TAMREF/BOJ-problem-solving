#include <cstdio>
#include <algorithm>

using namespace std;
int ss[100010], jy[100010];
int N, H, x, y, cnt, M = 222222;
bool c(int a, int b){return a<=b;}
int main()
{
    scanf("%d%d",&N,&H);
    for(int i=0;i<N/2;i++) scanf("%d%d",ss+i,jy+i);
    std::sort(ss,ss+N/2);
    std::sort(jy,jy+N/2);
    for(float g=0.5;g<=H;g++)
    {
        int V = lower_bound(jy,jy+N/2,H-g)-ss+upper_bound(ss,ss+N/2,g)-jy;
        V=N-V;
        //printf("g= %f : V = %d\n",g,V);
        if(V<M) M=V, cnt = 1;
        else if(V==M) ++cnt;
    }
    printf("%d %d\n",M,cnt);
}
