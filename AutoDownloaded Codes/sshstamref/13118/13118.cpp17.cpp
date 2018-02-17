#include <cstdio>
int main(){
    int p[4],x,c=0; scanf("%d%d%d%d",&p[0],&p[1],&p[2],&p[3]);
    scanf("%d%*d%*d",&x);for(int i=0;i<4;i++) if(p[i]==x) c=i+1; printf("%d\n",c);
}
