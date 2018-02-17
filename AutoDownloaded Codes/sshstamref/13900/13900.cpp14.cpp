#include <cstdio>
int N, a[111111];
long long ans, S;
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", a + i), S += a[i];
	for (int i = 0; i < N; i++)
	{
		S -= a[i];
		ans += S*a[i];
	}
	printf("%lld\n", ans);
}