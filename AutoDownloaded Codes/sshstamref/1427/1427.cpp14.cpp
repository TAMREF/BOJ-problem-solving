#include <stdio.h>
#include <string.h>
#include <algorithm>
char N[11];
int main()
{
    scanf("%s",N);
    int m=strlen(N);
    std::sort(N,N+m,std::greater<char>());
    puts(N);
}
