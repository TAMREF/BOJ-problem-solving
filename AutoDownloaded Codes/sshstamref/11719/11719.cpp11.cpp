#include <stdio.h>
int main(){
    char a[105]={};
    while(fgets(a,105,stdin)!=NULL) printf("%s",a);
}
