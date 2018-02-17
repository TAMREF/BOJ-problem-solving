#include <cstdio>
int main(){
    int s=0,m=12341234;
    for(int i=0,x;i<7;i++){
        scanf("%d",&x);
        if(x&1) s+=x,m=m<x?m:x;
    }
    if(s==0) puts("-1");
    else printf("%d\n%d\n",s,m);
}