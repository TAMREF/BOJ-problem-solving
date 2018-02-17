#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;
typedef long long ll;
const int MX = 200005;
struct point{
    ll x, y;
    point(ll _x=0, ll _y=0):x(_x),y(_y){}
    bool operator<(point z){return x<z.x||x==z.x&&y<z.y;}
    point operator-(point z){return point(x-z.x,y-z.y);}
    ll operator*(point z){return x*z.y-y*z.x;}
};
point operator~ (point u){return point(-u.x,-u.y);}
inline ll d(point u, point v=point()){
    u = u-v;return u.x*u.x+u.y*u.y;
}
inline bool cmp(point u, point v){
    return u*v<0||u*v==0&&d(u)<d(v);
}
point cv[MX];
int s_t;
point tam[MX];
int N, T;
int main(){
    for(scanf("%d",&T);T--;){
    s_t=0;
    scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%lld%lld",&tam[i].x,&tam[i].y);
    swap(tam[0],tam[min_element(tam,tam+N)-tam]);
    point O = tam[0]; O=~O;
    for(int i=N; i--;) tam[i]=tam[i]-tam[0];
    sort(tam+1,tam+N,cmp);
    for(int i=0; i<N; i++){
        while(s_t>1&&(tam[i]-cv[s_t-2])*(cv[s_t-1]-cv[s_t-2])<=0) --s_t;
        cv[s_t++]=tam[i];
    }
    int idx=0, jdx=max_element(cv,cv+s_t)-cv;
    point g, h;
    ll MAX=0, D;
    pair<point,point> ans;
    for(int i=0; i<s_t; i++){
        D=d(cv[idx],cv[jdx]);
        if(D>MAX){
            MAX=D; ans=make_pair(cv[idx],cv[jdx]);
        }
        g = cv[(idx+1)%s_t]-cv[idx], h=cv[(jdx+1)%s_t]-cv[jdx];
        ++(g*(~h)<=0?idx:jdx);
        idx%=s_t, jdx%=s_t;
    }
    ans.fst=ans.fst-O; ans.snd=ans.snd-O;
    printf("%lld %lld %lld %lld\n",ans.fst.x,ans.fst.y,ans.snd.x,ans.snd.y);
    }
}