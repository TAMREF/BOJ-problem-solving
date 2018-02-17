#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct pt{
    ll x,y;
    pt(ll x=0,ll y=0):x(x),y(y){}
    bool operator< (pt z){
        return x==z.x?y<z.y:x<z.x;
    }
    ll operator* (pt z){
        return x*z.y-y*z.x;
    }
    pt operator- (pt z){
        return pt(x-z.x,y-z.y);
    }
};
pt tam[100005], uh[100005], dh[100005];
int n,u,d;
void init(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>tam[i].x>>tam[i].y;
    sort(tam,tam+n);
}
void andrew(){
    for(int i=0;i<n;i++){
        while(u>1&&(uh[u-1]-uh[u-2])*(tam[i]-uh[u-2])<=0) --u;
        uh[u++]=tam[i];
    }
    for(int i=n;i--;){
        while(d>1&&(dh[d-1]-dh[d-2])*(tam[i]-dh[d-2])<=0) --d;
        dh[d++]=tam[i];
    }
    printf("%d\n",u+d-2);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    init();
    andrew();
}