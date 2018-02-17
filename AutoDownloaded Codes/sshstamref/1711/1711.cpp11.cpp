#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
const int MX=1505;
struct pt{
    ll x, y;
    pt(ll x=0, ll y=0):x(x),y(y){}
    inline bool operator< (pt z){return x<z.x||x==z.x&&y<z.y;}
    inline ll operator* (pt z){return x*z.y-y*z.x;}
    inline pt operator- (pt z){return pt(x-z.x,y-z.y);}
    inline pt operator~ (){return pt(-y,x);}
};
bool cmp(pt u, pt v){return u*v<0;}
pt tam[MX];
vector<pt> neigh[4][MX];
int N, cnt;
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%lld %lld",&tam[i].x,&tam[i].y);
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j) continue;
            pt u=tam[j]-tam[i];
            if(u.x>0&&u.y>=0) neigh[0][i].push_back(u);
            else if(u.x<=0&&u.y>0) neigh[1][i].push_back(u);
            else if(u.x<0&&u.y<=0) neigh[2][i].push_back(u);
            else neigh[3][i].push_back(u);
        }
        for(int t=0;t<4;t++) sort(all(neigh[t][i]),cmp);
        for(int t=0,v;t<4;t++){
            v=(t+1)%4;
            for(pt u : neigh[t][i]){
                cnt+=upper_bound(all(neigh[v][i]),~u,cmp)-lower_bound(all(neigh[v][i]),~u,cmp);
            }
        }
    }
    printf("%d\n",cnt);
}
