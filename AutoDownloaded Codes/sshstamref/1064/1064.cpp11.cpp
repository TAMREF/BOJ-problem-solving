#include <bits/stdc++.h>
using namespace std;
typedef double lf;
struct pt{
    lf x,y;
    pt(lf x=0, lf y=0):x(x),y(y){}
    bool operator<(pt z){return x==z.x?y<z.y:x<z.x;}
    pt operator-(pt z){return pt(x-z.x,y-z.y);}
    lf d(){return sqrt(x*x+y*y);}
    lf operator*(pt z){return x*z.y-y*z.x;}
};
bool lin(pt u,pt v,pt w){
    pt q[3]={u,v,w};
    sort(q,q+3);
    return fabs((w-u)*(v-u))<1e-9;
}
pt a[3];
int main(){
    for(int i=0;i<3;i++) scanf("%lf%lf",&a[i].x,&a[i].y);
    if(lin(a[0],a[1],a[2])) return 0&puts("-1");
    lf b[3];
    for(int i=0;i<3;i++) b[i]=(a[(i+1)%3]-a[i]).d();
    sort(b,b+3);
    printf("%.10f\n",2.*(b[2]-b[0]));
}