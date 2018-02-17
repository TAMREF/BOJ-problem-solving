#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX = 100005;
struct point{
    ll x, y;
    point(ll x=0, ll y=0):x(x),y(y){}
    bool operator<(point z){return x==z.x?y<z.y:x<z.x;}
    point operator-(point z){return point(x-z.x,y-z.y);}
    ll operator*(point z){return x*z.y-y*z.x;}
};
point operator~ (point u){return point(-u.x,-u.y);}
inline ll d(point u, point v=point()){
    u = u-v;return u.x*u.x+u.y*u.y;
}
inline bool cmp(point u, point v){
    ll T=u*v;
    return T?T<0:d(u)<d(v);
}
vector<point> cv;
point tam[MX];
int N;
int main(){
    scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%lld%lld",&tam[i].x,&tam[i].y);
    swap(tam[0],*min_element(tam,tam+N));
    for(int i=N; i--;) tam[i]=tam[i]-tam[0];
    sort(tam+1,tam+N,cmp);
    for(int i=0;i<N;i++){
        while(cv.size()>1&&(tam[i]-cv[cv.size()-2])*(cv.back()-cv[cv.size()-2])<=0) cv.pop_back();
        cv.push_back(tam[i]);
    }
    int idx=0, jdx=max_element(cv.begin(),cv.end())-cv.begin();
    point g, h;
    ll MAX=0;
    for(int i=0,C=cv.size();i<C;i++){
        MAX=max(MAX,d(cv[idx],cv[jdx]));
        g=cv[(idx+1)%C]-cv[idx], h=cv[(jdx+1)%C]-cv[jdx];
        (++(g*(~h)<=0?idx:jdx))%=C;
    }
    printf("%.8f\n",sqrt(MAX));
}
