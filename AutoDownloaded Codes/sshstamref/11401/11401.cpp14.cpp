#pragma warning (disable : 4996)
#include <cstdio>
#define rem 1000000007
inline long long inv(long long a, long long p)
{
	if (p == 1) return a;
	long long S = inv(a, p / 2);
	if (p & 1) return (((a*S) % rem)*S) % rem;
	else return (S*S) % rem;
}
inline long long fact(long long n, long long ub=1)
{
	long long P = 1;
	for (int i = ub; i <= n; i++)P = (P*i) % rem;
	return P;
}
long long n, k;
int main()
{
	scanf("%d %d", &n, &k);
	printf("%lld", (fact(n, n-k+1)*inv(fact(k), rem - 2)) % rem);
	return 0;
}