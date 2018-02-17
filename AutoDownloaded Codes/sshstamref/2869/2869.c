#include <stdio.h>
int a, b, v;
int main()
{
  scanf("%d%d%d",&a,&b,&v);
  if(v<=a) puts("1");
  else
  {
      printf("%d\n",(v-a)/(a-b)+1+((v-a)%(a-b)?1:0));
  }
}
