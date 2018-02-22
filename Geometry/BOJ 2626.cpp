#include <bits/stdc++.h>
using namespace std;

typedef long double lf;
const lf eps = 1e-8;

struct pt{
    lf x,y;
    pt(lf x=0,lf y=0):x(x),y(y){}
    pt operator- (pt z){
        return pt(x-z.x,y-z.y);
    }
    lf operator* (pt z){
        return x * z.y - y *z.x;
    }
    bool operator< (pt z){
        return fabs(x-z.x) < eps ? y < z.y : x < z.x;
    }
    lf operator^ (pt z){
        return sqrt((x-z.x) * (x-z.x) + (y-z.y) * (y-z.y));
    }
};

pt tam[1005], uh[1005], dh[1005], ch[1005];
int n;
int h;

unordered_set<unsigned int> S;

void input(){
    cin >> n;
    cout << fixed;
    cout.precision(3);
    unsigned int dx, dy;
    for(int i = 0, x, y; i < n; i++){
        cin >> x >> y;
        dx = x + 32768, dy = y + 32768;
        assert(S.find(dx << 16 | dy) == S.end());
        tam[i] = pt((lf)x, (lf)y);
        S.insert(dx << 16 | dy);
    }
}

void andrew(){
    sort(tam,tam+n);
    int ut = 0, dt = 0;
    for(int i=0;i<n;i++){
        while(ut > 1 && (tam[i] - uh[ut-2]) * (uh[ut-1] - uh[ut-2]) > 0) --ut;
        uh[ut++] = tam[i];
    }
    for(int i=n;i--;){
        while(dt > 1 && (tam[i] - dh[dt-2]) * (dh[dt-1] - dh[dt-2]) > 0) --dt;
        dh[dt++] = tam[i];
    }
    copy(uh,uh+ut,ch);
    copy(dh+1,dh+dt-1,ch+ut);
    h = ut + dt - 2;
    //for(int i = 0; i < h; i++) printf("%.6Lf, %.6Lf\n",ch[i].x,ch[i].y);
}

inline lf sq(lf x){return x * x;}
pt CircumCenter(pt u, pt v, pt w){
    pt nu = pt();
    lf Nu = sq(u ^ nu), Nv = sq(v ^ nu), Nw = sq(w ^ nu);
    lf A = (Nv - Nu) * (w.y - v.y) - (Nv - Nw) * (u.y - v.y);
    lf B = 2.L * ( (u.x - v.x) * (w.y - v.y) - (w.x - v.x) * (u.y - v.y) );
    lf C = (Nv - Nu) * (w.x - v.x) - (Nv - Nw) * (u.x - v.x);
    lf D = 2.L * ( (u.y - v.y) * (w.x - v.x) - (w.y - v.y) * (u.x - v.x) );
    assert( fabs(B) > eps && fabs(D) > eps );
    return pt(-A/B, -C/D);
}

lf radius(){
    pt O;
    lf rad = 1e18;
    for(int i=0;i<h;i++){
        for(int j=i+1;j<h;j++){
            lf lrad = ch[i] ^ ch[j];
            pt lO = pt(0.5L * (ch[i].x + ch[j].x), 0.5L * (ch[i].y + ch[j].y));
            if(lrad > rad) goto FAIL;
            for(int k=0;k<n;k++){
                if((lO ^ tam[k]) > lrad + eps) goto FAIL;
            }
            rad = lrad;
            O = lO;
            continue;
            FAIL:
            continue;
        }
    }
    for(int i=0;i<h;i++){
        for(int j=i+1;j<h;j++){
            for(int k=j+1;k<h;k++){
                pt lO = CircumCenter(ch[i],ch[j],ch[k]);
                lf lrad = lO ^ ch[i];
                if(lrad > rad) goto FAIL2;
                for(int m=0;m<n;m++){
                    if((lO ^ tam[m]) > lrad + eps) goto FAIL2;
                }
                rad = lrad;
                O = lO;
                continue;
                FAIL2:
                continue;
            }
        }
    }
    cout << O.x << ' ' << O.y << '\n';
    cout << rad << '\n';
    return rad;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    input();
    andrew();
    radius();
}
