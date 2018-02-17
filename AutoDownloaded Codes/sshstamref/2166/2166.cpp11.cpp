#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct pt{
    ll x,y;
    pt(ll x=0,ll y=0):x(x),y(y){}
    bool operator< (pt z){return x==z.x?y<z.y:x<z.x;}
    ll operator* (pt z){return x*z.y-y*z.x;}
    pt operator- (pt z){return pt(x-z.x,y-z.y);}
};
ll S(pt u, pt v, pt ori){
    return (u-ori)*(v-ori);
}
pt tam[10005];
int main(){
    cin.sync_with_stdio(false); cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>tam[i].x>>tam[i].y;
    ll A=0;
    for(int i=1;i<n-1;i++) A+=S(tam[i],tam[i+1],tam[0]);
    A=llabs(A);
    printf("%lld.%d\n",A/2LL,5*(A&1));
}