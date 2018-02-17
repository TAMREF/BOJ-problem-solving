#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx = 75005;

struct pt{
    int x, y;
} tam[mx];

int n;
int xp[mx], yp[mx], nx, ny;

struct BIT{
    int n, a[mx];
    BIT(int n=mx-1):n(n){memset(a,0,sizeof(a));}
    int sum(int i){
        int s = 0;
        for(;i;i-=(i&-i)) s += a[i];
        return s;
    }
    void add1(int i){
        for(;i<=n;i+=(i&-i)) ++a[i];
    }
} I;

void init(){
    cin >> n;
    I = BIT(n);
    for(int i=0;i<n;i++){
        cin >> tam[i].x >> tam[i].y;
        tam[i].y = -tam[i].y;
        xp[i] = tam[i].x; yp[i] = tam[i].y;
    }
    sort(xp,xp+n); nx = unique(xp,xp+n) - xp;
    sort(yp,yp+n); ny = unique(yp,yp+n) - yp;
    for(int i=0;i<n;i++){
        tam[i].x = lower_bound(xp,xp+nx,tam[i].x) - xp + 1;
        tam[i].y = lower_bound(yp,yp+ny,tam[i].y) - yp + 1;
    }
    sort(tam,tam+n,[](pt &u, pt &v){return u.x==v.x?u.y<v.y:u.x<v.x;});
}


ll cntpairs(){
    ll ans = 0;
    for(int i=0;i<n;i++){
        ans += I.sum(tam[i].y);
        I.add1(tam[i].y);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    for(cin>>t;t--;){
        init();
        cout << cntpairs() << '\n';
    }
}
