#include <iostream>
#define LIM 500
#define LONG long long
#define SIZEBIN 8*sizeof(LONG)
#define MOD 1000000

using namespace std;
struct Fibo
{
	LONG a[2][2];
	LONG index;
};

const Fibo E = { { 1,1,1,0 },0 };
Fibo space[LIM + 1];

Fibo operator* (Fibo x, Fibo y)
{
	Fibo z;
	z.a[0][0] = (x.a[0][0] * y.a[0][0] + x.a[0][1] * y.a[1][0]) % MOD;
	z.a[0][1] = (x.a[0][0] * y.a[0][1] + x.a[1][0] * y.a[1][1]) % MOD;
	z.a[1][0] = (x.a[1][0] * y.a[0][0] + x.a[1][1] * y.a[1][0]) % MOD;
	z.a[1][1] = (x.a[1][0] * y.a[0][1] + x.a[1][1] * y.a[1][1]) % MOD;
	z.index = x.index + y.index - 1;
	return z;
}




void save()
{
	Fibo t = { 1,1,1,0,0 };
	space[0] = t;
	for (int i = 0; i < LIM; i++)
	{
		space[i + 1] = (space[i] * space[i])*t;
		space[i + 1].index = -(i + 1);
	}
	return;
}
bool* binary(LONG n)
{
	bool* bin = new bool[SIZEBIN];
	for (int i = 1; i <= SIZEBIN; i++)
	{
		*(bin + SIZEBIN - i) = n % 2;
		n /= 2;
	}
	return bin;
}

Fibo getFib(LONG n)
{
	bool* bin = binary(n);
	bool* point = bin + SIZEBIN - 1;
	Fibo m = E;
	for (int i = 0; i < SIZEBIN; i++)
	{
		if (*(point--))
		{
			m = m*space[i - 1] * E;
		}
	}
	m.index = n;
	return m;
}
int getnum(LONG n)
{
	if (n % 2)
	{
		//printfib(getFib(n + 1));
		return getFib(n + 1).a[1][1];
	}
	else
	{
		//printfib(getFib(n));
		return getFib(n).a[0][1];
	}
}
int getindex(Fibo x)
{
	return x.index;
}
int main()
{
	save();
	LONG n;
	cin >> n;
	cout << getnum(n - 1);
	return 0;
}