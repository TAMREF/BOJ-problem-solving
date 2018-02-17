#include <cstdio>
#define PI 3.14159265358979323846264338
int R;
int main()
{
    scanf("%d",&R);
    printf("%.6Lf\n%.6Lf",PI*(long double)R*(long double)R,2.0*(long double)R*(long double)R);
}
