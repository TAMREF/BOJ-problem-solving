#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct point{
    ll x,y;
    point(ll x=0,ll y=0):x(x),y(y){}
    bool operator< (point z){return x==z.x?y<z.y:x<z.x;}
    point operator- (point z){return point(x-z.x,y-z.y);}
    ld operator/ (point z){return (ld)(y-z.y)/(x-z.x);}
    ll operator* (point z){return x*z.y-y*z.x;}
    ll operator& (point z){return (x-z.x)*(x-z.x)+(y-z.y)*(y-z.y);}
};
point tam[300005], cv[300005];
int top=1;
int N,K;
void input(){
    cin>>N>>K;
    for(int i=1,L;i<=N;i++){
        cin>>L;
        tam[i].x=i, tam[i].y=L+tam[i-1].y;
    }
}
int para(int j){
    int p=0,q,r,s=top-1;
    for(;p<s;){
        q=p+(s-p)/3, r=s-(s-p)/3;
        if(tam[j]/cv[q]<=tam[j]/cv[r]) p=q+1;
        else s=r-1;
    }
    return p;
}
void ins(int u){
    for(;top>1&&(tam[u]-cv[top-1])*(cv[top-1]-cv[top-2])>=0;) --top;
    cv[top++]=tam[u];
}
void solve(){
    ld U=0;
    for(int i=K;i<=N;i++){
        U=max(U,tam[i]/cv[para(i)]);
        ins(i-K+1);
    }
    cout<<U<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cout.setf(ios::fixed);
    cout.precision(10);
    input();
    solve();
    return 0;
}