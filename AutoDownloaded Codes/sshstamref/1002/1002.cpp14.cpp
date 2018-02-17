#include <cstdio>
int T, x1, y1, x2, y2, r1, r2;
int main()
{
    scanf("%d",&T);
    for(int i=0;i<T;i++){
    scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);
    long long dis=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2), dr=(r2-r1)*(r2-r1), sr=(r2+r1)*(r2+r1);
    if((x1==x2)&&(y1==y2)&&(r1==r2)) puts("-1");
    else
    {
        if((dis<dr)||(dis>sr)) puts("0");
        else if((dis==dr)||(dis==sr)) puts("1");
        else puts("2");
    }
    }
    return 0;
}
