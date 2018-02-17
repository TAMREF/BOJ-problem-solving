#include <cstdio>
#include <algorithm>
#include <vector>
#define fst first
#define snd second
#define all(x) x.begin(),x.end()
#define mp make_pair
using namespace std;
typedef long long ll;
const int MX=1505;
const ll INF=1e17;
struct pt{
    int x, y;
    ll d;
    pt(int x=0,int y=0):x(x),y(y){d=(ll)x*x+(ll)y*y;}
    pt(int x, int y, ll d):x(x),y(y),d(d){}
    ll operator* (pt z){return (ll)x*z.y-(ll)y*z.x;}
    pt operator- (pt z){return pt(x-z.x,y-z.y);}
};
bool operator< (pt u, pt v){
    ll T=u*v; return T?T<0:u.d<v.d;
}
pt tam[MX];
vector<pair<pt,int>> mtam[4][MX];
vector<pt> stam[4][MX];
int N;
void input_and_sort(){
    scanf("%d",&N);
    for(int i=0,x,y;i<N;i++){
        scanf("%d%d",&x,&y);
        tam[i]=pt(x,y);
    }
    for(int i=0;i<N;i++){
        for(int j=0,idx;j<N;j++){
            if(i==j) continue;
            pt u = tam[j]-tam[i];
            if(u.x>0&&u.y>=0) idx=0;
            else if(u.y>0&&u.x<=0) idx=1;
            else if(u.y<=0&&u.x<0) idx=2;
            else idx=3;
            mtam[idx][i].push_back({u,j});
        }
        for(int t=0;t<4;t++) sort(all(mtam[t][i]));
        for(int t=0;t<4;t++) for(auto v : mtam[t][i]) stam[t][i].push_back(v.fst);
    }
}
ll rectangle(){
    ll rmax=0;
    for(int i=0;i<N;i++){
        for(int t=0;t<4;t++){
            for(auto v : mtam[t][i]){
                pt u=v.fst;
                int a=lower_bound(all(mtam[(t+1)%4][i]),mp(pt(-u.y,u.x,0),0))-mtam[(t+1)%4][i].begin(),
                    b=upper_bound(all(mtam[(t+1)%4][i]),mp(pt(-u.y,u.x,INF),MX))-mtam[(t+1)%4][i].begin();

                for(int j=a,k;j<b;j++){
                    k=mtam[(t+1)%4][i][j].snd;
                    if(binary_search(all(stam[t][k]),u)) rmax=max(rmax,abs(mtam[(t+1)%4][i][j].fst*u));
                }
            }
        }
    }
    return rmax;
}
int main(){
    input_and_sort();
    printf("%lld\n",rectangle());
}
