#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct pt{
    ll x, y;
    pt(ll x=0,ll y=0):x(x),y(y){}
    ll operator*(pt z){
        return x * z.y - y * z.x;
    }
    pt operator-(pt z){
        return pt(x-z.x,y-z.y);
    }
    bool operator< (pt& z){
        return x==z.x?y<z.y:x<z.x;
    }
    bool operator== (pt z){
        return x==z.x&&y==z.y;
    }
};

int ccw(pt u, pt v, pt w){
    ll c = (v-u)*(w-u);
    return c?c>0?1:-1:0;
}

struct seg{
    pt a, b;
    seg(ll x=0,ll y=0,ll xx=0,ll yy=0){
        a = pt(x,y);
        b = pt(xx,yy);
        if(b<a) swap(a,b);
    }
    bool operator< (seg s){
        return a < s.a;
    }
} tam[20005];

bool intersect(seg& u, seg& v){
    int ab = ccw(u.a,u.b,v.a) * ccw(u.a,u.b,v.b) , cd = ccw(v.a,v.b,u.a) * ccw(v.a,v.b,u.b);
    if(ab==0 && cd==0){
        return !(u.b < v.a || v.b < u.a);
    }
    return ab <= 0 && cd <= 0;
}

int n;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    ll p,q,r,s;
    for(int i=0;i<n;i++){
        cin>>p>>q>>r>>s;
        tam[i] = seg(p,q,r,s);
    }
    sort(tam,tam+n);
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(tam[i].b < tam[j].a) break;

            if(cnt >= 100000){
                printf("%d\n",cnt);
                return 0;
            }

            cnt += intersect(tam[i], tam[j]);
        }
    }
    printf("%d\n",cnt);
}
