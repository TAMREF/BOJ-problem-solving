#include <bits/stdc++.h>
using namespace std;
typedef long double lf;
struct pt{
    lf x,y;
    pt(){}
    pt(lf x,lf y):x(x),y(y){}
    bool operator< (pt z){return x==z.x?y<z.y:x<z.x;}
    lf operator+ (pt z){return sqrt((x-z.x)*(x-z.x)+(y-z.y)*(y-z.y));}
    pt operator- (pt z){return pt(x-z.x,y-z.y);}
};
pt hound[105], sheep[1005];
vector<pt> allo[105];
int n,k;
void distribute(){
    lf md=1e18;
    for(int i=0;i<k;i++) allo[i].clear();
    for(int i=0,mi;i<n;i++){
        md=1e18; mi=-1;
        for(int j=0;j<k;j++){
            if(md>hound[j]+sheep[i]) md=hound[j]+sheep[i],mi=j;
        }
        allo[mi].push_back(sheep[i]);
    }
}
lf score(){
    lf dist=0;
    for(int i=0;i<k;i++){
        for(pt z : allo[i]) dist+=(z+hound[i]);
    }
    return dist;
}
void sample(){
    for(int i=0;i<k;i++) allo[i].clear();
    hound[0]=pt(1.75L,3.25L); hound[1]=pt(5.L,5.L);
}
void input(){
    cin>>n>>k;
    int fitx=1, fity=1;
    for(int i=0;i<n;i++){
        cin>>sheep[i].x>>sheep[i].y;
        fitx=max(fitx,(int)sheep[i].x);
        fity=max(fity,(int)sheep[i].y);
    }
    srand((unsigned int)time(0));
    for(int i=0;i<k;i++){
        hound[i]=pt((lf)(rand()%fitx+1),(lf)(rand()%fity+1));
    }
}
void eval(){
    distribute();
    printf("%.5Lf\n",score());
}
void output(){
    for(int i=0;i<k;i++) printf("%.6Lf %.6Lf\n",hound[i].x,hound[i].y);
}
int main(){
    cin.sync_with_stdio(false);cin.tie(0);
    input();
    //eval();
    output();
}