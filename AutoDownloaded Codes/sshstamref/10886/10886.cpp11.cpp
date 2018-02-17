#include <cstdio>
int main(){
    int n,c=0,t;
    for(scanf("%d",&n);n--;){
        scanf("%d",&t);
        c+=2*t-1;
    }
    printf("%s",c>0?"Junhee is cute!":"Junhee is not cute!");
}