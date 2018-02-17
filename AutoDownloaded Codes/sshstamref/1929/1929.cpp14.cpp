#include <cstdio>
bool vis[1111111];
void buildprime(int m, int n)
{
	int eop = 0, st = 0;
	if (m <= 2) puts("2");
	for (long long i = 3; i <= n; i += 2)
		if (!vis[i])
		{
			if (i >= m) printf("%d\n", i);
			for (long long j = i*i; j <= n; j += i) vis[j] = true;
		}
}
int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	buildprime(m, n);
}