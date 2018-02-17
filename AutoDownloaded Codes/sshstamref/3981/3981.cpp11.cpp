#include <cstdio>
#include <algorithm>
int T,N,i,t,x[555];
int main(){
    for(scanf("%d",&T);T--;){
        scanf("%d",&N);
        for(i=0;i<N;i++) scanf("%d",&x[i]);
        if(N<=3){puts("YES"); continue;}
        for(t=1;t<4;t++) for(int i=0;i<N-t;i++) x[i]=x[i+1]-x[i];
        puts(std::unique(x,x+N-3)-x==1?"YES":"NO");
    }
}