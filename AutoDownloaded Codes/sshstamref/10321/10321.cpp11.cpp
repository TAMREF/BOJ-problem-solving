#include <bits/stdc++.h>
#define inc(x) (((x)+1)%top)
using namespace std;
typedef long long ll;
struct point{
    int x, y;
    point(int a=0,int b=0):x(a),y(b){}
    bool operator<(point z){return x<z.x||x==z.x&&y<z.y;}
    int operator*(point z){return x*z.y-y*z.x;}
    point operator-(point z){return point(x-z.x,y-z.y);}
};
const point O=point();
int d(point u, point v=O){
    return (u.x-v.x)*(u.x-v.x)+(u.y-v.y)*(u.y-v.y);
}
inline int S(point u, point v, point w){
    return abs(u*v+v*w+w*u);
}
point tam[1005], cv[1005];
int N, T, top;
void input(){
    scanf("%d",&N); top=0;
    for(int i=0;i<N;i++) scanf("%d%d",&tam[i].x,&tam[i].y);
    swap(tam[0],*min_element(tam,tam+N));
    for(int i=N-1;i>=0;i--) tam[i]=tam[i]-tam[0];
    sort(tam+1,tam+N,[](point u, point v){return u*v<0||u*v==0&&d(u)<d(v);});
    for(int i=0;i<N;i++){
        while(top>1&&(tam[i]-cv[top-1])*(cv[top-1]-cv[top-2])<=0) --top;
        cv[top++]=tam[i];
    }
}
void query(){
    int area=0;
    if(top<3);
    else if(top==3) area=S(cv[0],cv[1],cv[2]);
    else{
        for(int i=0;i<top;i++){
            int s=inc(i),e=inc(i);
            for(int j=(i+1);j<top;++j){
                while(s!=j&&S(cv[i],cv[s],cv[j])<S(cv[i],cv[inc(s)],cv[j])) s=inc(s);
                while(e!=i&&S(cv[j],cv[e],cv[i])<S(cv[j],cv[inc(e)],cv[i])) e=inc(e);
                area=max(area,S(cv[i],cv[s],cv[j])+S(cv[j],cv[e],cv[i]));
            }
        }
    }
    printf("%d%s\n",area/2,area&1?".5":"");
}
int main(){
    for(scanf("%d",&T);T--;){
        top=0;
        input();
        query();
    }
}
