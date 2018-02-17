#include <cstdio>
int a[20003];
int main()
{
    int N, x;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&x);
        ++a[x+10000];
    }
    for(int i=0;i<20001;i++)
    {
        for(int j=0;j<a[i];j++) printf("%d\n",i-10000);
    }
    return 0;
}