#include <cstdio>
int f[1111] = { 1, 1 };
int main()
{
	int n;
	scanf("%d", &n);
	if (n < 2) printf("%d\n", f[n]);
	else{
		for (int i = 2; i <= n; i++) f[i] = (f[i - 1] + f[i - 2]) % 10007;
		printf("%d\n", f[n]);
	}
}