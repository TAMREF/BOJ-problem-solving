#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int> u;
typedef long long ll;
const int mx=500005;
int N, y[mx], tog[mx];
void input(){
    for(int x,i=0&scanf("%d",&N);i<N;i++){
        scanf("%d",&x);
        u[x]=i;
    }
    for(int i=0;i<N;i++){
        scanf("%d",&y[i]);
        y[i]=u[y[i]];
    }
}
ll cross(int s, int e){
    if(s==e) return 0;
    int m=(s+e)>>1;
    ll ncro = cross(s,m) + cross(m+1,e);
    int i=s,j=m+1,now=s;
    for(;i<=m&&j<=e;++now){
        y[i]>y[j]?(tog[now]=y[j++],ncro+=(ll)(m-i+1)):tog[now]=y[i++];
    }
    copy(y+i,y+m+1,tog+now);
    copy(y+j,y+e+1,tog+now);
    copy(tog+s,tog+e+1,y+s);
    return ncro;
}
int main(){
    input();
    printf("%lld\n",cross(0,N-1));
    return 0;
}