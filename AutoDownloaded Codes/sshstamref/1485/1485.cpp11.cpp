#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct point{
    ll x,y;
    point(ll x=0,ll y=0):x(x),y(y){}
    inline ll operator*(point z){return x*z.y-y*z.x;}
    inline point operator-(point z){
        return point(x-z.x,y-z.y);
    }
};
inline ll d(point u, point v=point()){
    return (u.x-v.x)*(u.x-v.x)+(u.y-v.y)*(u.y-v.y);
}
int main(){
    point tam[4];
    int T;
    for(cin>>T;T--;){
        for(int f=0;f<4;f++) cin>>tam[f].x>>tam[f].y;
        swap(tam[0],*min_element(tam,tam+4,[](point u, point v){
                return u.x==v.x?u.y<v.y:u.x<v.x;
             }));
        sort(tam+1,tam+4,[tam](point u, point v){
                ll L=(u-tam[0])*(v-tam[0]);
                return L?L<0:d(tam[0],u)<d(tam[0],v);
            });
        ll u[3];
        //for(int i=0;i<4;i++) cout<<tam[i].x<<' '<<tam[i].y<<endl;
        auto di=[tam](int i,int j)->ll{
            return d(tam[i],tam[j]);
        };
        for(int f=0;f<3;f++) u[f]=di(0,f+1);
        if(u[0]==u[2] && u[0]==di(1,2) && u[0]==di(2,3) && u[1]==2LL*u[0] && u[1] == di(1,3)) puts("1");
        else puts("0");
    }
    return 0;
}