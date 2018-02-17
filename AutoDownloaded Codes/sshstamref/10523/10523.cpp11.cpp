#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
random_device rd;
mt19937 gen(rd());
struct pt{
    ll x,y;
    pt(ll x=0,ll y=0):x(x),y(y){}
    pt operator- (pt z){
        return pt(x-z.x,y-z.y);
    }
    ll operator* (pt z){
        return x*z.y-y*z.x;
    }
};
inline int isbet(pt u, pt v, pt bet){
    return (int)((v-u)*(bet-u)==0);
}
pt tam[100005];
int N,p;
void input(){
    scanf("%d%d",&N,&p);
    for(int i=0;i<N;i++)
        scanf("%lld%lld",&tam[i].x,&tam[i].y);
}
inline bool pro(pt a, pt b){
    int cnt=0;
    for(int i=0;i<N;i++) cnt+=isbet(a,b,tam[i]);
    return cnt*100>=p*N;
}
int main(){
    input();
    if(N==1) return 0*puts("possible");
    int u,v;
    uniform_int_distribution<> d(0,N-1);
    for(int i=0;i<250;i++){
        u=d(gen), v=d(gen);
        if(u==v) continue;
        if(pro(tam[u],tam[v])) return 0*puts("possible");
    }
    puts("impossible");
}