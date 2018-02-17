#include <bits/stdc++.h>
using namespace std;
const int mx=100005;
typedef long long ll;
typedef pair<int,int> pii;
int coo[2][mx], comp[2][mx];
pii uaa[mx];
int L, N;
ll dp[2][mx],z,w,e;
int main(){
    scanf("%d%d",&N,&L);
    for(int i=0;i<N;i++){
        scanf("%d %d",&coo[0][i],&coo[1][i]);
        comp[0][i]=coo[0][i], comp[1][i]=coo[1][i];
    }
    sort(comp[0],comp[0]+N);
    sort(comp[1],comp[1]+N);
    int u=unique(comp[0],comp[0]+N)-comp[0], v=unique(comp[1],comp[1]+N)-comp[1];
    for(int i=0;i<N;i++){
        coo[0][i]=lower_bound(comp[0],comp[0]+u,coo[0][i])-comp[0];
        coo[1][i]=lower_bound(comp[1],comp[1]+v,coo[1][i])-comp[1];
        uaa[i]=pii(coo[0][i],coo[1][i]);
    }
    sort(uaa,uaa+N);
    for(int i=0;i<N;i++){
        e=llabs((ll)comp[0][uaa[i].first]-comp[1][uaa[i].second])+L;
        z=dp[0][uaa[i].first], w=dp[1][uaa[i].second];
        dp[0][uaa[i].first]=max(z,w+e);
        dp[1][uaa[i].second]=max(w,z+e);
    }
    printf("%lld\n",max(*max_element(dp[0],dp[0]+N),*max_element(dp[1],dp[1]+N)));
}