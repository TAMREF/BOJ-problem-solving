#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
inline ll di(pll u, pll v){
    return (u.va-v.va)*(u.va-v.va)+(u.vb-v.vb)*(u.vb-v.vb);
}
pll tam[105];
int path[105][105];
int main(){
    int N,D,R;
    scanf("%d %d %d %lld %lld",&N,&R,&D,&tam[0].va,&tam[0].vb);
    for(int i=1;i<=N;i++) scanf("%lld %lld",&tam[i].va,&tam[i].vb);
    for(int i=0;i<=N;i++) fill(path[i],path[i]+N+1,1<<20);
    for(int i=0;i<=N;i++)
        for(int j=0;j<=N;j++)
            if(i!=j && di(tam[i],tam[j])<=1LL*R*R) path[i][j]=1;
    for(int k=0;k<=N;k++)
        for(int i=0;i<=N;i++)
            for(int j=0;j<=N;j++)
                path[i][j]=min(path[i][j],path[i][k]+path[k][j]);
    double ans=0.0;
    for(int i=1;i<=N;i++) ans+=1.0/pow(2,path[i][0]-1);
    printf("%.2f\n",ans*D);
}