#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct pt{
    ll x, y, len;
    int sgn;
    pt(ll _x=0, ll _y=0, ll _len=0, ll _sgn=0):x(_x),y(_y),len(_len),sgn(_sgn){}
    ll operator* (pt z){return x*z.y-y*z.x;}
    pt operator- (pt z){return pt(x-z.x,y-z.y,len,sgn);}
};
inline pt a(pt u){
    if(u.y<0) return pt(-u.x,-u.y,u.len,-u.sgn);
    return u;
}
int N,i,j;
pt tam[4010], ding[4010];
void input(){
    scanf("%d",&N);
    ll X0, X1, Y;
    for(i=0;i<N;i++){
        scanf("%lld%lld%lld",&X0,&X1,&Y);
        if(X0>X1) swap(X0,X1);
        tam[2*i] = pt(X0,Y,X1-X0,1);
        tam[2*i+1] = pt(X1,Y,X1-X0,-1);
    }
}
ll opt(){
    ll profit = -1;
    for(i=0;i<N;i++){
        ll local = tam[2*i].len;
        copy(tam,tam+2*N,ding);
        swap(ding[0],ding[2*i]); swap(ding[1],ding[2*i+1]);
        for(j=2;j<2*N;j++) ding[j]=a(ding[j]-ding[0]);
        sort(ding+2,ding+2*N,[=](pt u, pt v){return u*v<0||(u*v==0 && u.sgn>v.sgn);});
        for(j=2;j<2*N;j++){
            if(ding[j].y==0) continue;
            local+=ding[j].sgn*ding[j].len;
            profit = max(profit,local);
        }
        profit = max(profit,local);
    }
    return profit;
}
int main(){
    input();
    printf("%lld\n",opt());
    return 0;
}