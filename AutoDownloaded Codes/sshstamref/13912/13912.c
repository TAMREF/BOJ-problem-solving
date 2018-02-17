#include <stdio.h>
typedef long long L;int MOD=1e9+7;L C[] = {1,2,20,3432,155117520,997262645,899707189,876105808,746311539,856578165,8323437};
L f(int n){L T; return n?(T=f(n-1),(C[n]*T%MOD)*T%MOD):1;}
main(n){scanf("%d", &n);printf("%d\n", f(n));}