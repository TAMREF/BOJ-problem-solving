#include <cstdio>
#include <algorithm>
using namespace std;
int M, N, x[1003], summax[1003];
int main()
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&x[i]);
        for(int j=i-1;j>=0;j--)
            if(x[i]>x[j]) summax[i]=max(summax[i],summax[j]);
        summax[i]+=x[i];
    }
    for(int i=1;i<=N;i++) M=max(M,summax[i]);
    printf("%d\n",M);
    return 0;
}
