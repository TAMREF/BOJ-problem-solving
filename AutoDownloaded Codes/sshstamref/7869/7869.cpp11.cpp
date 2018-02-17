#include <bits/stdc++.h>
using namespace std;
typedef double lf;
struct circle{
    lf x, y, r;
    lf d2(circle z){
        return (z.x-x)*(z.x-x)+(z.y-y)*(z.y-y);
    }
    lf S(){return acos(-1)*r*r;}
    lf inter(circle z){
        lf del = d2(z);
        if(del>=(r+z.r)*(r+z.r)) return 0.0;
        if(del<=(r-z.r)*(r-z.r)) return min(S(),z.S());
        lf c1=(r*r+del-z.r*z.r)/(2*r*sqrt(del)), c2=(z.r*z.r+del-r*r)/(2*z.r*sqrt(del));
        lf t1=acos(c1), t2=acos(c2);
        return r*r*t1+z.r*z.r*t2-sqrt(del)*r*sin(t1);
    }
} c[2];
int main(){
    for(int i=0;i<2;i++) cin>>c[i].x>>c[i].y>>c[i].r;
    printf("%.3f\n",c[0].inter(c[1]));
}
