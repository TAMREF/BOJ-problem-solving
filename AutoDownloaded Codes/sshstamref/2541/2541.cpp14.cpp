#include <stdio.h>
int a, b, t, i, x, y, now, sign;
int main() {
    scanf("%d%d",&a,&b);
    t = b-a;
    if (t > 0) sign = 1;
    else if (t < 0) sign = -1, t = -t;
    while (t > 0 && !(t&1)) t >>= 1;
    for (i = 1; i <= 5; i++){
        scanf("%d%d",&x,&y);
        now = y-x;
        if (sign < 0) now = -now;
        if (sign == 0)
            (now)?(puts("N")):(puts("Y"));
        else 
            ((now<=0||(now%t)))?(puts("N")):(puts("Y"));
    }
    return 0;
}