#include <cstdio>
#include <algorithm>

using namespace std;

int nop[1000003];

int main()
{
    int N;
    scanf("%d",&N);
    nop[2]=nop[3]=1;
    for(int i=2;i<N;i++)
    {
        if(3*i<=N){
        if(nop[3*i]) nop[3*i]=min(nop[i]+1,nop[3*i]);
        else nop[3*i]=nop[i]+1;
        }
        if(2*i<=N){
        if(nop[2*i]) nop[2*i]=min(nop[i]+1,nop[2*i]);
        else nop[2*i]=nop[i]+1;
        }
            if(nop[i+1]) nop[i+1]=min(nop[i]+1,nop[i+1]);
            else nop[i+1]=nop[i]+1;
    }
    printf("%d\n",nop[N]);
}
