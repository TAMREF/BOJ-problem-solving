#include <stdio.h>

typedef unsigned long ULONG;
ULONG Fibonacci(int N)
{
	int i;
	ULONG* FiboTable;

	FiboTable = (ULONG*)malloc(sizeof(int)*(N + 1));

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
	printf("%d", Fibonacci(n-1));
	return 0;
}