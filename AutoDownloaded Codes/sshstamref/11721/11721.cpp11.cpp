#include <cstdio>
#include <cstring>
char a[105], b[11];
int main(){
    scanf("%s",a);
    for(int i=0;i<strlen(a);i+=10){
        strncpy(b,a+i,10);
        puts(b);
    }
}