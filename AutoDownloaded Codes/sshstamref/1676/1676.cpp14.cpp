#include <cstdio>
int n,cn, V;
int main()
{
	scanf("%d",&n);
	cn=n;
	while(n>0) V+=(n%5), n/=5; 
	printf("%d\n",(cn-V)/4);
}