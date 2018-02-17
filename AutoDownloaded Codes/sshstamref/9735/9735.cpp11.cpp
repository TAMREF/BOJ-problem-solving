#include <bits/stdc++.h>
using namespace std;

typedef long double lf;

const lf eps = 1e-8;

lf a,b,c,d,p,q,s[3],det;
int n, y;

lf calc(lf x){
    return ((a * x + b) * x + c) * x + d;
}
int main(){
    for(cin >> n ; n-- ; ){
        cin >> a >> b >> c >> d;
        for(y = -1000000 ; y <= 1000000 ; y++){
            if(fabs( calc (y) ) < eps) break;
        }
        s[0] = (lf)y + 1e-13;
        p = b + a * y;
        q = c + p * y;
        det = p * p - 4.L * a * q;
        if(fabs(det) < eps){
            s[1] = - p / a / 2.L;
            if(s[0] > s[1]) swap(s[0],s[1]);
            if(fabs(s[0]) < 1e-4) s[0] = fabs(s[0]);
            if(fabs(s[1]) < 1e-4) s[1] = fabs(s[1]);
            if(fabs(s[0]) < eps + 1e6) printf("%.4Lf ",s[0]);
            if(fabs(s[0] - s[1]) > 1e-4 && fabs(s[1]) < eps + 1e6) printf("%.4Lf ",s[1]);
            puts("");
        }else if(det < 0){
            if(fabs(s[0]) < 1e-4) s[0] = fabs(s[0]);
            if(fabs(s[0]) < eps + 1e6) printf("%.4Lf",s[0]);
            puts("");
        }else{
            s[1] = -(p + sqrt(det))/a/2.L, s[2] = -(p-sqrt(det))/a/2.L;
            sort(s,s+3);
            if(fabs(s[0]) < 1e-4) s[0] = fabs(s[0]);
            if(fabs(s[1]) < 1e-4) s[1] = fabs(s[1]);
            if(fabs(s[2]) < 1e-4) s[2] = fabs(s[2]);
            if(fabs(s[0]) < eps + 1e6) printf("%.4Lf ",s[0]);
            if(fabs(s[0] - s[1]) > 1e-4 && fabs(s[1]) < eps + 1e6) printf("%.4Lf ",s[1]);
            if(fabs(s[1] - s[2]) > 1e-4 && fabs(s[2]) < eps + 1e6) printf("%.4Lf ",s[2]);
            puts("");
        }
    }
}
