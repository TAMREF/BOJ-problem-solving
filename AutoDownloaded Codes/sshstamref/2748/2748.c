#include <stdio.h>

typedef long long LONG;
LONG Fibonacci(int N)
{
	int i;
	LONG* FiboTable;

	FiboTable = (LONG*)malloc(sizeof(int)*(N + 1));

	FiboTable[0] = 0;
	FiboTable[1] = 1;
	for (i = 2; i <N+2; i++)
	{
		FiboTable[i] = FiboTable[i - 1] + FiboTable[i - 2];
	}
	return FiboTable[N+1];
	
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%lld", Fibonacci(n-1));
	return 0;
}