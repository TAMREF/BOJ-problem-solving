#include <bits/stdc++.h>
using namespace std;
const int mn = 10005;
int pa, a, b, c, N, w;
int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&w);
        a=max(pa,max(b,c));
        c=b+w;
        b=pa+w;
        pa=a;
    }
    printf("%d\n",max(a,max(b,c)));
}
