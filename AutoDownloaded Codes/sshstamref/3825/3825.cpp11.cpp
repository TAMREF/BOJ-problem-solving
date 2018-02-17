#include <cstdio>
int T, a, b, R, flag;
inline long long sq(int z){return 1LL*z*z;}
int main()
{
    scanf("%d",&T);
    for(int v=0;v<T;v++)
    {
        flag=0;
        scanf("%d %d",&a,&b);
        R=a*a+b*b;
        for(int i=0;i*i<=R;i++)
        {
            for(int j=0;sq(i*i+j*j)<=R;j++)
                if(i*i+j*j && !(R%(i*i+j*j))) ++flag;
        }
        putchar((flag>2)?('C'):('P'));
        putchar(10);
    }
    return 0;
}