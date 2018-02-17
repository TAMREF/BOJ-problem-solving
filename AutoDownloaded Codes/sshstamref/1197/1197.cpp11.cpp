#include <bits/stdc++.h>
using namespace std;
int V, E;
vector<int> link[10005];
int rep[10005];
pair<int,pair<int,int>> ej[100005];
int f(int x){return x==rep[x]?x:rep[x]=f(rep[x]);}
void c(int x, int y){
    x=f(x), y=f(y);
    rep[y]=x;
}
int main(){
    scanf("%d%d",&V,&E);
    long long W=0;
    for(int i=1;i<=V;i++) rep[i]=i;
    for(int i=0;i<E;i++) scanf("%d%d%d",&ej[i].second.first,&ej[i].second.second,&ej[i].first);
    sort(ej,ej+E);
    for(int i=0;i<E;i++){
        if(f(ej[i].second.first)==f(ej[i].second.second)) continue;
        W+=(long long)ej[i].first;
        c(ej[i].second.first,ej[i].second.second);
    }
    printf("%lld\n",W);
}
