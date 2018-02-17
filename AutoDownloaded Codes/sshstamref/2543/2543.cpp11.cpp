#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main(){
    int N,d[100005]={1}; pii tam[100005];
    const int m=20070713;
    auto cmp=[](pii u, pii v){return u.second<v.second;};
    for(int i=scanf("%d",&N);i<=N;i++) scanf("%d %d",&tam[i].first,&tam[i].second);
    sort(tam+1,tam+N+1,cmp);
    for(int i=1;i<=N;i++)
        d[i]=(d[i-1]+d[upper_bound(tam+1,tam+i,make_pair(0,tam[i].first),cmp)-tam-1])%m;
    printf("%d\n",d[N]);
}