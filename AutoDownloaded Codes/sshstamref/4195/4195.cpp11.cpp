#include <bits/stdc++.h>
using namespace std;
int rep[100005], sz[100005];
unordered_map<string,int> u;
inline int f(int x){
    return x==rep[x]?x:rep[x] = f(rep[x]);
}
inline int c(int x, int y){
    x=f(x),y=f(y);
    if(x==y) return sz[x];
    if(sz[x]<sz[y]) swap(x,y);
    rep[y] = x;
    return sz[x]+=sz[y];
}
char buf[25], buf2[25];
string b1, b2;
int main(){
    int T,n,m1,m2;
    for(scanf("%d\n",&T);T--;){
        scanf("%d",&n);
        u.clear();
        fill(sz,sz+100002,1);
        iota(rep,rep+100002,0);
        for(int i=0;i<n;i++){
            scanf("%*c%s %s",buf,buf2);
            b1 = string(buf), b2 = string(buf2);
            if(!u[b1]) m1 = u[b1] = u.size()+1;
            if(!u[b2]) m2 = u[b2] = u.size()+1;
            m1 = u[b1], m2 = u[b2];
            printf("%d\n",c(m1,m2));
        }
    }
}