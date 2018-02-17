#include <cstdio>
int main(){
    int n,f;
    scanf("%d%d",&n,&f);
    for(n=n/100*100;n%f;n++);
    printf("%02d",n%100);
}