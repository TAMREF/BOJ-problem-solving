#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX = 30005;
struct pt{
    ll x, y;
    pt(ll x=0,ll y=0):x(x),y(y){}
    ll operator* (pt z){return x*z.y-y*z.x;}
    bool operator< (pt z){return x<z.x||x==z.x&&y<z.y;}
    pt operator- (pt z){return pt(x-z.x,y-z.y);}
};
inline ll d(pt z, pt w=pt()){return (z.x-w.x)*(z.x-w.x)+(z.y-w.y)*(z.y-w.y);}
pt tam[MX], uc[MX], dc[MX], u[MX], v[MX];
int N,T,ut,dt;
void input(){
    scanf("%d%d",&N,&T);
    for(int i=0;i<N;i++) scanf("%lld%lld%lld%lld",&u[i].x,&u[i].y,&v[i].x,&v[i].y);
}
void graham(){
    swap(tam[0],*min_element(tam,tam+N));
    for(int i=N;i--;) tam[i]=tam[i]-tam[0];
    sort(tam,tam+N);
    for(int i=ut=dt=0;i<N;i++){
        while(ut>1&&(tam[i]-uc[ut-2])*(uc[ut-1]-uc[ut-2])<=0) --ut;
        uc[ut++]=tam[i];
    }
    for(int i=N;i--;){
        while(dt>1&&(tam[i]-dc[dt-2])*(dc[dt-1]-dc[dt-2])<=0) --dt;
        dc[dt++]=tam[i];
    }
}
ll RC(){
    int idx=0, jdx=0; ll D=0; pt g, h;
    for(int i=0,t=ut+dt-2;i<t;i++){
        D=max(D,d(uc[idx],dc[jdx]));
        if(idx==ut-1) ++jdx;
        else if(jdx==dt-1) ++idx;
        else{
            ++((uc[idx+1]-uc[idx])*(dc[jdx+1]-dc[jdx])>=0?idx:jdx);
        }
    }
    return D;
}
ll pro(int t){
    for(int i=0;i<N;i++){
        tam[i].x=u[i].x+v[i].x*t;
        tam[i].y=u[i].y+v[i].y*t;
    }
    graham();
    return RC();
}
int main(){
    input();
    int p=0, q, r, s=T;
    while(p<s){
        q=p+(s-p)/3, r=s-(s-p)/3;
        if(pro(q)<=pro(r)) s=r-1;
        else p=q+1;
    }
    printf("%d\n%lld\n",p,pro(p));
}