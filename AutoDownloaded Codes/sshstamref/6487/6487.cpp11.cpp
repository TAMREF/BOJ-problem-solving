#include <bits/stdc++.h>
using namespace std;
struct point{
    int x, y;
    point(int x=0,int y=0):x(x),y(y){}
    point operator- (point z){
        return point(x-z.x,y-z.y);
    }
    int operator* (point z){
        return x*z.y-y*z.x;
    }
} p[4];
int main(){
    int T;
    for(cin>>T;T--;){
        for(int i=0;i<4;i++)
            cin>>p[i].x>>p[i].y;
        if((p[0]-p[1])*(p[2]-p[3])==0){
            puts((p[0]-p[1])*(p[0]-p[2])?"NONE":"LINE");
        } else{
            printf("POINT %.2f ",(double)((p[0]*p[1])*(p[2].x-p[3].x)-(p[0].x-p[1].x)*(p[2]*p[3]))/((p[0]-p[1])*(p[2]-p[3])));
            printf("%.2f\n",(double)((p[0]*p[1])*(p[2].y-p[3].y)-(p[0].y-p[1].y)*(p[2]*p[3]))/((p[0]-p[1])*(p[2]-p[3])));
        }
    }
}
