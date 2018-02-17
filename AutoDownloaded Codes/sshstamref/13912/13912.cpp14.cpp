#include <cstdio>
#include <cmath>
#define MOD 1000000007
int n;
long long C[] = {1,2,20,3432,155117520,997262645,899707189,876105808,746311539,856578165,8323437};
long long f(int n)
{
	if (!n) return 1;
	long long T = f(n - 1);
	return (C[n] * T%MOD)*T%MOD;
}
int main()
{
	scanf("%d", &n);
	printf("%d\n", f(n));
}
