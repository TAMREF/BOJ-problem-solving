#include <cstdio>
int main(){
    int s,e,m;
    scanf("%d%d%d",&e,&s,&m);
    for(int i=1;i<=7980;i++){
        if((i-1)%15+1==e&&(i-1)%19+1==m&&(i-1)%28+1==s) return 0*printf("%d\n",i);
    }
}