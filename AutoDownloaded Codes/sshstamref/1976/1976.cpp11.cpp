#include <bits/stdc++.h>
using namespace std;
int N,M,adj[203][203],rep[203],p[2];
int f(int x){return x==rep[x]?x:(rep[x]=f(rep[x]));}
void c(int x, int y){x=f(x),y=f(y);rep[y]=x;}
int main(){
    int N,M;
    scanf("%d%d",&N,&M);
    iota(rep,rep+N,0);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&adj[i][j]);
            if(adj[i][j]) c(i,j);
        }
    }
    scanf("%d",&p[0]);
    for(int i=1;i<M;i++){
        scanf("%d",&p[1]);
        if(f(p[1])!=f(p[0])) return 0*puts("NO");
    }
    puts("YES");
}