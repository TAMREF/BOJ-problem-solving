#include <cstdio>
#include <cstring>
int main(){
    char a[101];
    scanf("%s",a);
    for(int i=0;i<strlen(a);i++)
        a[i]=a[i]>='a'?a[i]-'a'+'A':a[i]-'A'+'a';
    puts(a);
}