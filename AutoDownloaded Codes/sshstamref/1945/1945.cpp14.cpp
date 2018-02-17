#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX = 10005;
int N;
struct point{
    ll x, y;
    int idx;
    point(ll _x=0, ll _y=0, ll _i=0):x(_x),y(_y),idx(_i){}
};
ll c(point u, point v){
    return u.x*v.y-u.y*v.x;
}
point tam[2*MX];
void input(){
    scanf("%d",&N);
    ll xl, yl, xr, yr;
    for(int i=0;i<N;i++){
        scanf("%lld%lld%lld%lld",&xl,&yl,&xr,&yr);
        tam[2*i]=point(xl,yr,1);
        tam[2*i+1]=point(xr,yl);
    }
    sort(tam,tam+2*N,[=](point u, point v){return c(u,v)<0||c(u,v)==0&&u.idx>v.idx;});
}
int sweep(){
    int maxcnt=0, cnt=0;
    for(int i=0;i<2*N;i++){
        tam[i].idx?++cnt:--cnt;
        maxcnt=max(maxcnt,cnt);
    }
    return maxcnt;
}
int main()
{
    //freopen("input.txt","rt",stdin);
    input();
    return 0*printf("%d\n",sweep());
}
