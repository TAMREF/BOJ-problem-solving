#include <cstdio>
int a, b, c;
main()
{
    scanf("%d %d %d",&a,&b,&c);
    printf("%d\n%d\n%d\n%d\n",(a+b)%c,(a+b)%c,(a*b)%c,(a*b)%c);
    return 0;
}