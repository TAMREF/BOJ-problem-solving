#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans;
vector<int> a[4], ab, cd;
int N, i,j,x[4];
int main(){
    scanf("%d",&N);
    for(i=0;i<N;i++){
        for(j=0;j<4;j++){
            scanf("%d",&x[j]);
            a[j].push_back(x[j]);
        }
    }
    for(i=0;i<N;i++)
        for(j=0;j<N;j++){
            ab.push_back(a[0][i]+a[1][j]);
            cd.push_back(a[2][i]+a[3][j]);
        }
    sort(ab.begin(),ab.end()); sort(cd.begin(),cd.end());
    for(auto &u : ab){
        ans+=upper_bound(cd.begin(),cd.end(),-u)-lower_bound(cd.begin(),cd.end(),-u);
    }
    printf("%lld\n",ans);
}