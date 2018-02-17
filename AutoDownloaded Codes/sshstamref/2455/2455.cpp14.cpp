#include <cstdio>
#include <algorithm>
int P,O, R, M, N;
int main()
{
    for(int i=0;i<4;i++)
    {
        scanf("%d%d",&O,&R);
        P=P-O+R;
        M=std::max(M,P);
    }
    printf("%d\n",M);
}
