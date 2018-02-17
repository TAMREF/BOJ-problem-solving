#include <bits/stdc++.h>
using namespace std;
const int MAXN=1005;
typedef long long ll;
struct point{
    ll x, y;
    point(ll x=0, ll y=0):x(x),y(y){}
    inline bool operator<(point z){return x<z.x||x==z.x&&y<z.y;}
    inline ll operator*(point z){return x*z.y-y*z.x;}
    inline point operator-(point z){return point(x-z.x,y-z.y);}
    inline ll d(){return x*x+y*y;}
} tam[MAXN], cv[MAXN], jail;
inline bool cmp(point u, point v){
    ll t=u*v;
    return t<0||!t&&u.d()<v.d();
}
vector<point> ding, appa;
int N, top, wall, mark[MAXN];
void input(){
    scanf("%d %lld %lld",&N,&jail.x,&jail.y);
    for(int i=0;i<N;i++) scanf("%lld %lld",&tam[i].x,&tam[i].y);
    ding.assign(tam,tam+N);
}
void graham(){
    appa.clear();
    swap(ding[0],*min_element(ding.begin(),ding.end()));
    jail=jail-ding[0];
    for(auto r=ding.rbegin();r!=ding.rend();r++) *r=*r-ding[0];
    sort(ding.begin()+1,ding.end(),cmp);
    for(int i=top=0;i<ding.size();i++){
        while(top>1&&(ding[i]-cv[top-1])*(cv[top-1]-cv[top-2])<=0) appa.push_back(cv[--top]);
        cv[top++]=ding[i];
    }
}
bool isin(){
    int t=lower_bound(cv+1,cv+top,jail,cmp)-cv;
    return (jail-cv[t])*(cv[t]-cv[t-1])>=0;
}
int main(){
    input();
    for(;ding.size();wall++){
        graham();
        if(!isin()) return 0*printf("%d\n",wall);
        ding.clear(); ding.assign(appa.begin(),appa.end());
    }
    printf("%d\n",wall);
}