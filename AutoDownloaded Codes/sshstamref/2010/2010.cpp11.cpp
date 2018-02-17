#include <cstdio>
int main(){
    int n,S=0;scanf("%d",&n);
    for(int i=0,x;i<n;i++){
        scanf("%d",&x);
        S+=x;
    }
    printf("%d",S-n+1);
}
