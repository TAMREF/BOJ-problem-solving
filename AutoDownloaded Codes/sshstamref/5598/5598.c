#include <stdio.h>
char a[1003];main(){gets(a);for(int i=0;a[i];i++){a[i]-=3;if(a[i]<'A') a[i]+=26;}puts(a);}