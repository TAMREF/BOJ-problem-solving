#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX = 250005;
bool type[2*MX];
int G[2*MX], hj[2*MX], maa[2*MX], iron[2*MX];
int i, N, U;
ll ans;
inline int idx(int r){
    return lower_bound(iron,iron+U,r)-iron;
}
inline int f(int x){
    return (x==G[x])?x:G[x]=f(G[x]);
}
void unite(int x, int y){
    x=f(x), y=f(y);
    if(x==y) type[x]=true;
    type[x]=type[x]||type[y];
    G[y]=x;
}
void input(){
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d %d",&hj[2*i],&hj[2*i+1]);
        ans+=hj[2*i]+hj[2*i+1];
    }
    copy(hj,hj+2*N,iron);
    sort(iron,iron+2*N);
    U=unique(iron,iron+2*N)-iron;
    for(i=0;i<U;i++) G[i]=i;
    for(i=0;i<N;i++){
        hj[2*i]=idx(hj[2*i]), hj[2*i+1]=idx(hj[2*i+1]);
        unite(hj[2*i],hj[2*i+1]);
    }
}
void sep(){
    for(i=0;i<U;i++){
        maa[f(i)]=max(maa[G[i]],iron[i]);
        ans-=iron[i];
    }
    for(i=0;i<U;i++) if(i==G[i] && !type[i]) ans+=maa[i];
    printf("%lld\n",ans);
}
int main(){
    input();
    sep();
}
