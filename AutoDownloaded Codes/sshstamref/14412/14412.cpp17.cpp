#include <bits/stdc++.h>
using namespace std;
const int mx=1005;
bool G[mx][mx];
int rep[mx<<1], sz[mx<<1], V, E;
inline int f(int x){return x==rep[x]?x:rep[x]=f(rep[x]);}
void c(int x,int y){
    x=f(x), y=f(y);
    if(sz[x]<sz[y]) swap(x,y);
    sz[x]+=sz[y];
    rep[y]=x;
}
void input(){
    scanf("%d%d",&V,&E);
    for(int i=0,a,b;i<E;i++){
        scanf("%d%d",&a,&b);
        G[a][b]=G[b][a]=true;
    }
    for(int i=1;i<=(V<<1);i++) rep[i]=i, sz[i]=1;
}
void unite(){
    for(int i=1;i<=V;i++){
        for(int j=1;j<i;j++){
            if(G[i][j]){
                c(i,j);
                c(V+i,V+j);
            }else{
                c(i,V+j);
                c(V+i,j);
            }
        }
    }
}
bool det(){
    for(int i=1;i<=V;i++) if(f(i)==f(V+i)) return false;
    return true;
}
int main(){
    input();
    unite();
    puts(det()?"DA":"NE");
}